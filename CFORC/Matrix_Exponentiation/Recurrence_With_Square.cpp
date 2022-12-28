#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, mn, K, p, q, r, M = 1e9+7;
vector<int> a, c;

struct mat {
  vector<vector<int>> v;
  mat(){
    v.resize(mn+1, vector<int>(mn+1, 0));
  }
  
  mat operator * (const mat &m) const {
    mat res;
    for(int i = 1; i <= mn; i++)
      for(int j = 1; j <= mn; j++)
        for(int k = 1; k <= mn; k++)
          res.v[i][j] = (res.v[i][j] + (v[k][j] * m.v[i][k]) % M) % M;
    return res;
  }
};

mat matpow(mat a, int b){
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
  cin >> n >> K;
  a.resize(n);
  c.resize(n+1);
  for(int i = 0; i <= n-1; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> c[i];
  cin >> p >> q >> r;
  for(int i = n; i <= 9; i++){
    int A = 0;
    for(int k = 1; k <= n; k++)
      A = (A + ((c[k]*a[i-k])%M))%M;
    A = (A + p) % M;
    A = (A + (i*q)%M) % M;
    A = (A + (((i*i)%M)*r)%M) % M;
    a.push_back(A);
  }
  mn = 16;
  mat X;
  for(int i = 1; i <= n; i++)
    X.v[i][1] = c[i];
  X.v[1][2] = // a9
  X.v[2][3] = X.v[3][4] = X.v[4][5] = X.v[5][6] = X.v[6][7] = X.v[7][8] = X.v[8][9] = X.v[9][10] = 1;

  X.v[11][1] = X.v[12][1] = X.v[14][1] = X.v[11][11] = X.v[12][12] = 
  X.v[13][12] = X.v[13][13] = X.v[14][14] = X.v[15][14] = X.v[15][15] =
  X.v[16][15] = X.v[16][16] = 1;
  
  if(K <= 9){
    cout << a[K] << "\n";
    return 0;
  }
  X = matpow(X, K-10);
  vector<int> Y = {0, a[9], a[8], a[7], a[6], a[5], a[4], a[3], a[2], a[1], a[0], 1*p, (10*q)%M, 1*q, (100*r)%M, (21*r)%M, (2*r)%M};
  int A = 0;
  for(int i = 1; i <= mn; i++)
    A = (A + (Y[i] * X.v[i][1])%M)%M;
  cout << A << "\n";
}
