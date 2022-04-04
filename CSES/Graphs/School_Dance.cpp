// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Kuhn's Algorithm for Maximum Bipartite Matching
#include <bits/stdc++.h>
using namespace std;

int n, m, k, nr;
vector<vector<int>> G;
vector<int> mt, vis;

bool match(int v){
  if(vis[v] == nr)
    return false;
  vis[v] = nr;

  for(int x : G[v])
    if(!mt[x] || match(mt[x])){
      mt[x] = v;
      return true;
    }

  return false;
}

int main(){
  cin >> n >> m >> k;

  int allnodes = n+m;
  G.resize(allnodes+1);

  for(int i = 1; i <= k; i++){
    int a, b;
    cin >> a >> b;
    b += n;
    G[a].push_back(b);
  }

  vis.resize(allnodes+1, 0);
  mt.resize(allnodes+1, 0);
  nr = 0;
  for(int i = 1; i <= n; i++){
    nr++;
    match(i);
  }

  vector<pair<int, int>> ans;
  for(int i = 1; i <= m; i++)
    if(mt[i+n])
      ans.push_back({mt[i+n], i});

  cout << ans.size() << "\n";
  for(auto &p : ans)
    cout << p.first << " " << p.second << "\n";
}