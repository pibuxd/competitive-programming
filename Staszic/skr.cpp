// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll a, b, p;

bool is_prime(ll n){
  if(n <= 1)
    return false;
  if(n <= 3)
    return true;

  if(n % 2 == 0 || n % 3 == 0)
    return false;

  for(ll i = 5; i * i <= n; i = i + 6)
    if(n % i == 0 || n % (i + 2) == 0)
      return false;

  return true;
}

void foo(ll v){
  if(!is_prime(v))
    return;

  if(a <= v && v <= b)
    p++;

  foo(v*10 + 1);
  foo(v*10 + 3);
  foo(v*10 + 7);
  foo(v*10 + 9);
}

int main(){
  fastio;
  cin >> a >> b;
  p = 0;

  foo(2);
  foo(3);
  foo(5);
  foo(7);

  cout << p << '\n';
}