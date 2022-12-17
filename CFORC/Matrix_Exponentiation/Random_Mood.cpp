#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define float long double

int n;
float p;

struct mat{
  float a, b, c, d;

  mat operator * (const mat &m) const {
    float _a = m.a * a + m.b * c;
    float _b = m.a * b + m.b * d;
    float _c = m.c * a + m.d * c;
    float _d = m.c * b + m.d * d;
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

int main(){
  fastio;
  cin >> n >> p;
  mat m = {1-p, p, p, 1-p};
  m = matrixpow(m, n-1);
  cout << fixed << setprecision(10) << m.a << "\n";
}
