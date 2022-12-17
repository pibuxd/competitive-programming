#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, q, k, M = 1e9+7;

struct mat{
  vector<vector<int>> V;

  mat operator * (const mat &m) const {
    mat res;
    res.V.resize(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        int x = 0;
        for(int t = 1; t <= n; t++)
          x = (x + (V[t][j] * m.V[i][t]) % M) % M;
        res.V[i][j] = x;
      }
    }
    return res;
  }
};

mat matrixpow(mat &a, int b){
  mat res = a;
  while(b > 0){
    if(b % 2 == 1)
      res = res * a;
    a = a * a;
    b /= 2;
  }
  return res;
}

signed main(){
  fastio;
  cin >> n >> q >> k;
  mat m;
  m.V.resize(n+1, vector<int>(n+1));

  while(q--){
    int a, b; cin >> a >> b;
    m.V[a][b] = 1; 
  }
  
  m = matrixpow(m, k-1);
  int sum = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      sum = (sum + m.V[i][j]) % M;
  cout << sum << "\n";
}
