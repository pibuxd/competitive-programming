// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Kuhn's Algorithm for Maximum Bipartite Matching
// given a bipartite graph 
// select as many edges as possible so that 
// no selected edge shares a vertex with any other selected edge.
#include <bits/stdc++.h>
using namespace std;

int n, m, nr;
vector<vector<int>> G;
vector<int> mt, vis;

bool match(int v){
  if(vis[v] == nr)
    return false;
  vis[v] = nr;

  for(int x : G[v])
    if(!mt[x]){
      mt[x] = v;
      return true;
    }
  for(int x : G[v])
    if(match(mt[x])){
      mt[x] = v;
      return true;
    }
  return false;
}

int main(){
  cin >> n >> m;

  G.resize(n+1);
  mt.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vis.resize(n+1);
  mt.resize(n+1);
  nr = 0;
  for(int i = 1; i <= n; i++){
    nr++;
    match(i);
  }

  int sum = 0;
  for(int i = 1; i <= n; i++){
    cout << i << ": " << mt[i] << "\n";
    if(mt[i])
      sum++;
  }

  if(sum == n)
    cout << "Perfect matching!\n";
}