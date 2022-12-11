#include <bits/stdc++.h>
using namespace std;
#define int long long

array<int, 3> gcdext(int a, int b){
  if(b == 0)
    return {1, 0, a};

  auto [x, y, g] = gcdext(b, a%b);
  return {y, x-y*(a/b), g};
}

// solve linear diophantine equation x*a + y*b = c
bool solve(int a, int b, int c, int &x, int &y){ 
  auto [_x, _y, g] = gcdext(abs(a), abs(b));
  x = _x, y = _y;
  if(c % g != 0)
    return false;
  x *= c/g;
  y *= c/g;
  if(a < 0) x = -x;
  if(b < 0) y = -y;
  return true;
}

signed main(){
  int a, b, c; cin >> a >> b >> c;
  int x, y;
  if(solve(a, b, c, x, y))
    cout << x << " " << y << "\n";
  else
    cout << "CANT SOLVE THIS EQUATION\n";
}
