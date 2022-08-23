// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Sparse Table (RMQ)
// I use precomputed logarithm table to reduce logn in query()
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int LOGN = 19;
int n, q;
vector<vector<int>> sparse;
vector<int> lg;

void build(){
  for(int j = 1; j <= LOGN-1; j++)
    for(int i = 1; i + (1 << (j-1)) <= n; i++)
      sparse[i][j] = min(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
  
  for(int i = 2; i <= n; i++)
    lg[i] = lg[i/2] + 1;
}

int query(int a, int b){
  int len = b - a + 1;
  int j = lg[len];
  return min(sparse[a][j], sparse[b-(1<<j)+1][j]);
}

int main(){
  fastio;
  cin >> n >> q;
  sparse.resize(n+1, vector<int>(LOGN));
  lg.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> sparse[i][0];
  
  build();

  while(q--){
    int a, b;
    cin >> a >> b;
    cout << query(a, b) << "\n";
  }
}