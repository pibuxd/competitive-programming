// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Topological sort in DAG (Directed Acyclic Graph)
// * DFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
vector<bool> vis;
vector<int> top_sort;

void dfs(int v){
  vis[v] = true;

  for(int x : G[v])
    if(!vis[x])
      dfs(x);
  
  top_sort.push_back(v);
} 

int main(){
  cin >> n >> m;
  G.resize(n+1);
  vis.resize(n+1);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i);

  reverse(top_sort.begin(), top_sort.end());

  for(int x : top_sort)
    cout << x << " ";
}