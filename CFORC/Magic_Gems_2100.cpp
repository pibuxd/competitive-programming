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
          res.V[i][j] = (res.V[i][j] + (m.V[t][j] * V[i][t]) % M) % M;
    return res;
  }
};

mat matrixpow(mat &st, mat &a, int b){
  mat res = st;
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
  mat st;
  st.V.resize(n+1, vector<int>(n+1));
  for(int i = 1; i < n; i++)
    st.V[1][i] = 1;
  st.V[1][n] = 2;

  mat res = matrixpow(st, m, N-n);
  cout << res.V[1][n] << "\n";
}
