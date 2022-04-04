// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int a, b;
  cin >> a >> b;

  int mx = max({
    a+b,
    a-b,
    a*b
  });

  if((mx == a+b && mx == a-b) ||
     (mx == a+b && mx == a*b) ||
     (mx == a-b && mx == a*b)){
    cout << "NIE";
    return 0;
  }

  if(a < 0)
    cout << "(" << a << ")";
  else
    cout << a;
  if(mx == a+b){
    cout << "+";
  }
  if(mx == a-b){
    cout << "-";
  }
  if(mx == a*b){
    cout << "*";
  }
  if(b < 0)
    cout << "(" << b << ")";
  else
    cout << b;

  cout << "=";
  if(mx < 0)
    cout << "(" << mx << ")";
  else
    cout << mx;
}