// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Sparse Table (RMQ)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int LOGN = 19;
int n, q;
vector<vector<int>> sparse;

void build(){
  for(int j = 1; j <= LOGN-1; j++)
    for(int i = 1; i + (1 << (j-1)) <= n; i++)
      sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
}

int query(int a, int b){
  int len = b - a + 1;
  int j = floor(log2(len));
  return min(sparse[a][j], sparse[b-(1<<j)+1][j]);
}

int main(){
  fastio;
  cin >> n >> q;
  sparse.resize(n+1, vector<int>(LOGN));

  for(int i = 1; i <= n; i++)
    cin >> sparse[i][0];
  
  build();

  while(q--){
    int a, b;
    cin >> a >> b;
    cout << query(a, b) << "\n";
  }
}