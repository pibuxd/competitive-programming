// * binary lifting/jumping
// * using binary representation and DFS
// tree
#include <bits/stdc++.h>
using namespace std;

int LOGN;
vector<vector<int>> up, childs;

int kth_ancestor(int node, int k){
  for(int i = 0; i < LOGN; i++)
    if((k >> i) & 1) // or k & (1 << j), binary representation of n (19 = 16 + 2 + 1)
      node = up[node][i];

  if(!node)
    return -1;

  return node;
}

void dfs(int x){
  for(int v : childs[x]){
    for(int i = 1; i < LOGN; i++)
      up[v][i] = up[up[v][i-1]][i-1];

    dfs(v);
  }
}

int main(){
  int n, m;
  cin >> n >> m;

  // if this wouldn't be "+ 1",
  // tree with height equal to n would be bugged when k = n 
  LOGN = ceil(log2(n)) + 1;
  
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
    int node, k;
    cin >> node >> k;
    
    cout << kth_ancestor(node, k) << "\n";
  }
}