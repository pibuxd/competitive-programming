// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * binary lifting/jumping
// * using binary representation and DFS
// tree
#include <bits/stdc++.h>
using namespace std;

int LOGN, n, m;
vector<vector<int>> up;

int kth_ancestor(int node, int k){
  for(int i = 0; i <= LOGN; i++)
    if((k >> i) & 1) // or k & (1 << j), binary representation of n (19 = 16 + 2 + 1)
      node = up[node][i];

  if(!node)
    return -1;

  return node;
}

void calculate(){
  for(int j = 1; j <= LOGN; j++)
    for(int i = 1; i <= n; i++)
      up[i][j] = up[up[i][j-1]][j-1]; // because 2^4 = 2^3+2^3
} 

int main(){
  cin >> n >> m;
  LOGN = ceil(log2(n));
  
  up = vector<vector<int>>(n+1, vector<int>(LOGN+1));
  up[1][0] = 0;

  for(int i = 2; i <= n; i++)
    cin >> up[i][0];
  
  calculate();

  while(m--){
    int node, k;
    cin >> node >> k;
    
    cout << kth_ancestor(node, k) << "\n";
  }
}