// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q, logn;
vector<vector<int>> up;

int lift(int x, int k){
  for(int i = 0; i < logn; i++)
    if((k >> i) & 1)
      x = up[x][i];
  return x;
}

int main(){
  fastio;
  cin >> n >> q;
  logn = 30;
  up.resize(n+1, vector<int>(logn+1));

  for(int i = 1; i <= n; i++)
    cin >> up[i][0];

  for(int j = 1; j < logn; j++)
    for(int i = 1; i <= n; i++)
      up[i][j] = up[up[i][j-1]][j-1];

  while(q--){
    int x, k;
    cin >> x >> k;
    cout << lift(x, k) << "\n";
  }
}