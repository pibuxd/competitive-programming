#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, N;
vector<vector<int>> G, Grev;
vector<bool> vis;
vector<int> order, components, scc;

// (a v b) <=> (~a => b) && (~b => a)
void addedge(int a, int b){
  int nota = a^1, notb = b^1;
  G[nota].push_back(b);
  G[notb].push_back(a);
  Grev[b].push_back(nota);
  Grev[a].push_back(notb);
}

void dfs1(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs1(x);
  order.push_back(v);
}

void dfs2(int v){
  vis[v] = true;
  components.push_back(v);

  for(int x : Grev[v])
    if(!vis[x])
      dfs2(x);
}

int main(){
  fastio;
  cin >> n >> m;
  N = 2*n+1;

  G.resize(N+1);
  Grev.resize(N+1);
    
  for(int i = 1; i <= m; i++){
    int a, b, c; cin >> a >> b >> c;
    a = 2*a, b = 2*b;
    int nota = a^1, notb = b^1;

    if(c == 1){ // (~a v b) && (a v ~b)
      addedge(nota, b), addedge(a, notb);
    } else{ // (a v b) && (~a v ~b)
      addedge(a, b), addedge(nota, notb);
    }
  }

  vis.assign(N+1, false);
  for(int i = 1; i <= N; i++)
    if(!vis[i])
      dfs1(i);

  vis.assign(N+1, false);
  reverse(all(order));
  scc.assign(N+1, 0);
  int id = 0;

  for(int v : order){
    if(!vis[v]){
      dfs2(v);

      id++;
      for(int c : components)
        scc[c] = id;

      components.clear();
    }
  }

  for(int i = 1; i <= n; i++)
    if(scc[2*i] == scc[2*i+1]){
      cout << "Impossible\n";
      return 0;
    }
  
  vector<int> ans;
  for(int i = 1; i <= n; i++)
    if(scc[2*i] > scc[2*i+1])
      ans.push_back(i);
  
  cout << ans.size() << "\n";
  for(int i : ans)
    cout << i << " ";
  cout << "\n";
}
