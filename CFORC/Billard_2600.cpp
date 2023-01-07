// euclidean extended + infiniting grid
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long
 
int n, m, x, y, vx, vy;
pair<int, int> A, B, C, D;
 
int gcdext(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcdext(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void f(int a, int b){
    if(a == 0 && b == 0) cout << A.first << " " << A.second << "\n";
    else if(a == 1 && b == 0) cout << B.first << " " << B.second << "\n";
    else if(a == 1 && b == 1) cout << C.first << " " << C.second << "\n";
    else if(a == 0 && b == 1) cout << D.first << " " << D.second << "\n";
}
 
signed main(){
  fastio;
  cin >> n >> m >> x >> y >> vx >> vy;
  A = {0, 0}, B = {n, 0}, C = {n, m}, D = {0, m};
start:
  
  if(vx == -1 && vy == -1){ x = n-x, y = m-y; swap(A, D); swap(B, C); }
  else if(vx == -1 && vy == 1){
    int _x = x, _y = y;
    x = _y, y = n-_x;
    swap(n, m);
    //A = {0, 0}, B = {n, 0}, C = {n, m}, D = {0, m};
    swap(D, A); swap(A, C); swap(A, B);
  }
  else if(vx == 1 && vy == -1){
    int _x = x, _y = y;
    x = m-_y, y = _x;
    swap(n, m);
    //A = {0, 0}, B = {n, 0}, C = {n, m}, D = {0, m};
    swap(A, B); swap(A, C); swap(A, D);
  }
  else if(vx == 0 && vy == 1){
    if(x == 0){ cout << 0 << " " << m << "\n"; return 0;}
    if(x == n){ cout << n << " " << m << "\n"; return 0;}
    else{ cout << -1 << "\n"; return 0;}
 
  } else if(vx == 0 && vy == -1){
    if(x == 0){ cout << 0 << " " << 0 << "\n"; return 0;}
    if(x == n){ cout << n << " " << 0 << "\n"; return 0;}
    else{ cout << -1 << "\n"; return 0;}
 
  } else if(vx == 1 && vy == 0){
    if(y == 0){ cout << n << " " << 0 << "\n"; return 0;}
    if(y == m){ cout << n << " " << m << "\n"; return 0;}
    else{ cout << -1 << "\n"; return 0;}
 
  } else if(vx == -1 && vy == 0){
    if(y == 0){ cout << 0 << " " << 0 << "\n"; return 0;}
    if(y == m){ cout << 0 << " " << m << "\n"; return 0;}
    else{ cout << -1 << "\n"; return 0;}
  }
  
  int c = x-y;
  if(c == 0){
    if(n == m){ f(1, 1); return 0; }
    else if(n < m)
      x = n-1, y = n+1, vx = -1;
    else // m < n
      x = m+1, y = m-1, vy = -1;
    goto start;
  }

  //int c = (x-y) % M;
  //int c = x-y;
  if(c % __gcd(n, m) != 0){ cout << -1 << "\n"; return 0;}
  int a = 0, b = 0;
  int g = gcdext(n, -m, a, b);
  a *= c/g;
  b *= c/g;
  if(x-y != a*n-b*m) a = -a, b = -b;
  //cout << c << "\n";
  //cout << a << " " << b << "\n";
  f(a%2, b%2);
}
