#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int unsigned long long

int n, N, M = 1e9+7;

struct mat{
  vector<vector<int>> V;

  mat operator * (const mat &m) const {
    mat res;
    res.V.resize(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        for(int t = 1; t <= n; t++)
          res.V[i][j] = (res.V[i][j] + (V[t][j] * m.V[i][t]) % M) % M;
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
  cin >> N >> n;
  mat m;
  m.V.resize(n+1, vector<int>(n+1));
  if(N < n){ cout << 1 << "\n"; return 0; }

  for(int i = 1; i < n; i++)
    m.V[i+1][i] = 1;
  m.V[1][n] = m.V[n][n] = 1;

  m = matrixpow(m, N-n+1);
  int sum = 0;
  for(int i = 1; i <= n; i++)
    sum = (sum + m.V[1][i]) % M;
  cout << sum << "\n";
}
