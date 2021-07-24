// * Find a Centroid
// * using DFS
// tree
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<int> sub;

int dfs(int v, int p){
  sub[v] = 1;
  for(int x : G[v])
    if(x != p)
      sub[v] += dfs(x, v);

  return sub[v];
}

int find_centroid(int v, int p){
  for(int x : G[v])
    if(x != p && sub[x] > n/2)
      return find_centroid(x, v);

  return v;
}

int main(){
  cin >> n;
  G.resize(n+1);
  sub.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  cout << find_centroid(1, 0);
}