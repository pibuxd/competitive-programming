#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, A, B;

int gcdext(int a, int b, int &x, int &y){ // a*x + b*y = 1
  if(b == 0){
    x = 1, y = 0;
    return a;
  }
  int x1 = 0, y1 = 0;
  int d = gcdext(b, a%b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int getdiff(int x, int _x){
  int res = 0;
  if((abs(x) == x) == (abs(_x) == _x)){
    if(abs(x) > abs(_x))
      res += abs(x) - abs(_x);
  }
  else{
    res += abs(x);
  }
  return res;
}

int pushto(int a, int b, int g, int &x, int &y, int _x, int _y){
  int ret = getdiff(x, _x) + getdiff(y, _y);
  
   
}

bool findsol(int a, int b, int c, int &x, int &y, int _x, int _y, int &sum){
  int g = gcdext(abs(a), abs(b), x, y);
  if(c % g != 0)
    return false;
  
  x *= c / g;
  y *= c / g;
  sum += pushto(a, b, g, x, y, _x, _y);
  return true;
}

signed main(){
  fastio;
  cin >> n >> A >> B;
  int _x = 0, _y = 0, x = 0, y = 0, sum = 0;
  for(int i = 1; i <= n; i++){
    int h; cin >> h;
    if(!findsol(A, B, h, x, y, _x, _y, sum)){
      cout << "-1\n";
      return 0;
    }
    _x = x, _y = y; 
  }
}
