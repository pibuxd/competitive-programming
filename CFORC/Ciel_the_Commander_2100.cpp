// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Centroid Decomposition
// * calculate depth[node] of centroid decomposition tree
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Centroid_Decomposition{
  int n;
  vector<vector<int>> G;
  vector<int> sub, depth;
  vector<bool> visited;

  Centroid_Decomposition(int _n){
    n = _n;
    G.resize(n+1);
    sub.resize(n+1);
    depth.resize(n+1);
    visited.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int dfs(int v, int p){
    if(visited[v]) return 0;
    sub[v] = 1;
    for(int x : G[v])
      if(x != p)
        sub[v] += dfs(x, v);

    return sub[v];
  }

  int find_centroid(int v, int p, int t_size){
    for(int x : G[v])
      if(!visited[x] && x != p && sub[x] > t_size/2)
        return find_centroid(x, v, t_size);

    return v;
  }

  void decompose(int v, int p, int rank){
    int t_size = dfs(v, p);
    int centroid = find_centroid(v, p, t_size);
    visited[centroid] = true;
    depth[centroid] = rank;

    for(int x : G[centroid])
      if(!visited[x])
        decompose(x, centroid, rank+1);
  }

  int operator[](int i){
    return depth[i];
  }
};

int main(){
  fastio;
  int n;
  cin >> n;
  Centroid_Decomposition ranks(n); 
  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    ranks.push(a, b);
  }

  ranks.decompose(1, -1, 0);

  for(int i = 1; i <= n; i++)
    cout << (char)('A'+ranks[i]) << " ";
}