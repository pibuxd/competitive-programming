// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * LCA – Lowest Common Ancestor using binary lifting/jumping
#include <bits/stdc++.h>
using namespace std;

int LOGN;
vector<int> depth;
vector<vector<int>> up, childs;

void dfs(int x){ // calculating binary lifting
  for(int v : childs[x]){
    depth[v] = depth[x] + 1;
    for(int i = 1; i < LOGN; i++)
      up[v][i] = up[up[v][i-1]][i-1];

    dfs(v);
  }
}

int lca(int a, int b){
  if(depth[a] < depth[b])
    swap(a, b);
  int k = depth[a] - depth[b];

  for(int i = 0; i < LOGN; i++)
    if((k >> i) & 1)
      a = up[a][i];

  if(a == b)
    return a;

  for(int i = LOGN - 1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
  
}

int main(){
  int n, m;
  cin >> n >> m;

  // if this wouldn't be "+ 1",
  // tree with height equal to n would be bugged when k = n 
  LOGN = ceil(log2(n)) + 1;
  
  depth = vector<int>(n+1);
  childs = vector<vector<int>>(n+1);
  up = vector<vector<int>>(n+1, vector<int>(LOGN));
  up[1][0] = 0;

  for(int i = 2; i <= n; i++){ // get input
    int parent;
    cin >> parent;

    up[i][0] = parent;
    childs[parent].push_back(i);
  }
  
  dfs(1); // starting at root
  
  while(m--){
    int a, b;
    cin >> a >> b;
    
    cout << lca(a, b) << "\n";
  }
}