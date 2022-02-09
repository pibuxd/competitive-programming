#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int n, x1;
vector<int> g, sub, par;
vector<bool> vis;
vector<vector<int>> G;
int sii;

void bfs(int p, int f){
  par[p] = f;
  sii++;
  vis[p] = true;
  for(int x : G[p]){
    if(!vis[x]){
      bfs(x, p);
    }
  }
}

int ans(int x){
  auto it = G[x].begin();
  for(int i = 0; i < G[x].size(); i++){
    if(G[x][i] == par[x])
      G[x].erase(it);
    it++;
  }

  it = G[par[x]].begin();
  for(int i = 0; i < G[par[x]].size(); i++){
    if(G[par[x]][i] == x)
      G[par[x]].erase(it);
    it++;
  }

  sub.assign(n+1, 0);
  par.assign(n+1, 0);
  vis.assign(n+1, false);
  sii = 0;
  bfs(x, 0);
  
  return sii;
}

int main(){
  fastio;
  cin >> n >> x1;

  g.resize(n+1);
  G.resize(n+1);

  for(int i = 1; i <= n-2; i++) cin >> g[i];

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  sub.assign(n+1, 0);
  par.assign(n+1, 0);
  vis.assign(n+1, false);
  sii = 0;
  bfs(1, 0);

  indexed_set S;
  for(int i = 2; i <= n; i++) S.insert(i);

  int y = ans(x1);
  cout << y << "\n";
  S.erase(S.find_by_order(x1));
  
  for(int i = 1; i <= n-2; i++){
    int l = (y + g[i])%(n - i - 1) + 1;
    auto node = S.find_by_order(l-1);
    y = ans(*node);
    cout << y << "\n";
    S.erase(node);
  }
}