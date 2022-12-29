#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int unsigned long long

int k, f1, f2, f3, c, M = 1e9+7, M1 = 1e9+6, n = 14;

struct mat{
  vector<vector<int>> V;
  
  mat(){
    V.assign(n+1, vector<int>(n+1, 0));
  }

  mat operator * (const mat &m) const {
    mat res;
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        for(int t = 1; t <= n; t++)
          res.V[i][j] = (res.V[i][j] + (m.V[t][j] * V[i][t] % M1)) % M1;
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

int intpow(int a, int b){
  int res = 1;
  while(b > 0){
    if(b % 2 == 1)
      res = (res * a) % M;
    a = (a * a) % M;
    b /= 2;
  }
  return res;
}

signed main(){
  fastio;
  cin >> k >> f1 >> f2 >> f3 >> c;
  mat m;
  m.V = {{0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

         {0,  1, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
         {0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
         {0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
         {0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
         {0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
         {0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0,  0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}};

  mat res = matrixpow(m, k-5);

  vector<int> y = {0, 1, 2, 1, 1, 1, 2, 1, 0, 0, 0, 0, 1, 0, 0};
  int p3, p2, p1, pc;
  p3 = p2 = p1 = pc = 0;
  for(int i = 1; i <= n; i++)
    p3 = (p3 + (y[i] * res.V[i][3]) % M1) % M1;
  for(int i = 1; i <= n; i++)
    p2 = (p2 + (y[i] * res.V[i][4]) % M1) % M1;
  for(int i = 1; i <= n; i++)
    p1 = (p1 + (y[i] * res.V[i][5]) % M1) % M1;
  for(int i = 1; i <= n; i++)
    pc = (pc + (y[i] * res.V[i][6]) % M1) % M1;
  
  int sum = 1;
  sum = (sum * intpow(f1, p1))%M;
  sum = (sum * intpow(f2, p2))%M;
  sum = (sum * intpow(f3, p3))%M;
  sum = (sum * intpow(c, pc))%M;
  cout << sum << "\n";
}
