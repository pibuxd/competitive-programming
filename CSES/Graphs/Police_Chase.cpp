// * find min-cut in unweighted, undirected graph
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> G;
map<array<int, 2>, bool> taken, tak;
vector<array<int, 2>> mincut;
vector<bool> vis;
set<int> jd;

bool dfs(int v){
  vis[v] = true;
  if(v == n)  
    return true;

  for(int x : G[v]){
    if(taken[{v, x}])
      continue;
    
    if(!vis[x] && dfs(x)){
      taken[{v, x}] = true, taken[{x, v}] = false;
      tak[{v, x}] = true;
      return true;
    }
  }

  return false;
}

void _dfs(int v){
  if(v == n) return;
  vis[v] = true;

  for(int x : G[v]){
    if(!tak[{v, x}] && !vis[x])
      _dfs(x);
    else if(tak[{v, x}])
      jd.insert(v);
  }
}

int main(){  
  fastio;
  cin >> n >> m;
  G.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
    taken[{a, b}] = false;
    taken[{b, a}] = false;
  }

  vis.assign(n+1, false);
  while(dfs(1))
    vis.assign(n+1, false);

  vis.assign(n+1, false);
  _dfs(1);

  for(int v : jd)
    for(int x : G[v])
      if(tak[{v, x}] && !vis[x])
        mincut.push_back({v, x});

  cout << mincut.size() << "\n";
  for(auto p : mincut)
    cout << p[0] << " " << p[1] << "\n";
}