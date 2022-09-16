// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Find a Centroid
// * using DFS
// tree
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<int> sub, centroids;

void dfs(int v, int p){
  bool iscent = true;

  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);

    sub[v] += sub[x] + 1;
    if(sub[x] + 1 > n/2)
      iscent = false;
  }
  if(iscent && (n-sub[v]-1) <= n/2)
    centroids.push_back(v);
}

int main(){
  cin >> n;
  G.resize(n+1);
  sub.resize(n+1, 0);

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  for(int c : centroids) cout << c << " ";
}
