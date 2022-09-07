#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, M;
vector<vector<int>> G, Grev;
vector<bool> vis;
vector<int> order, scc;

void addg(int a, int b){
  G[a].push_back(b);
  Grev[b].push_back(a);
}

void addedge(int a, int b){ // (a v b) && (~a v ~b)
  a *= 2, b *= 2;
  addg(a^1, b);
  addg(b^1, a);
  addg(a, b^1);
  addg(b, a^1);
}

void dfs1(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs1(x);
  order.push_back(v);
}

void dfs2(int v, int id){
  vis[v] = true;
  scc[v] = id;
  for(int x : Grev[v])
    if(!vis[x])
      dfs2(x, id);
}

int main(){
  fastio;
  cin >> n >> m;
  M = 2*m+1;
  G.resize(M+1);
  Grev.resize(M+1);
  
  vector<array<int, 2>> v(m+1);
  
  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    v[i] = {a, b};
  }

  for(int i = 1; i <= m; i++){
    auto [x, y] = v[i];
    if(x > y) swap(x, y);
    for(int j = i+1; j <= m; j++){
      auto [a, b] = v[j];
      if(a > b) swap(a, b);
      if(a == x || b == x || a == y || b == y) continue;

      if((a < y && a < x && b > x && b < y) ||
         (a > y && a < x && b > x && b < y))
        addedge(i, j);
      else{
        swap(a, x); swap(b, y);
        if((a < y && a < x && b > x && b < y) ||
           (a > y && a < x && b > x && b < y))
          addedge(i, j);
        swap(a, x); swap(b, y);
      }
    }
  }
 
  vis.assign(M+1, false);
  for(int i = 1; i <= M; i++)
    if(!vis[i])
      dfs1(i);
  reverse(all(order));
  vis.assign(M+1, false);
  scc.assign(M+1, 0);
  int id = 0;
  for(int i : order)
    if(!vis[i])
      dfs2(i, ++id);
  
  for(int i = 1; i <= m; i++)
    if(scc[2*i] == scc[2*i+1]){
      cout << "Impossible\n";
      return 0;
    }
  for(int i = 1; i <= m; i++)
    cout << (scc[2*i] > scc[2*i+1] ? "i" : "o");
  cout << "\n";
}
