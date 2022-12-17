#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, M = 1e9+7;

struct mat{
  int a, b, c, d;

  mat operator * (const mat &m) const {
    int _a = (m.a * a + m.b * c)%M;
    int _b = (m.a * b + m.b * d)%M;
    int _c = (m.c * a + m.d * c)%M;
    int _d = (m.c * b + m.d * d)%M;
    return {_a, _b, _c, _d};
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
  cin >> n;
  if(n == 0){ cout << 0 << "\n"; return 0; }
  mat m = {1, 1, 1, 0};
  m = matrixpow(m, n-2);
  cout << m.a << "\n";
}
