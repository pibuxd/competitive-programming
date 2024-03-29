// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Greatest Common Divisor using Euclidean algorithm
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b, a%b);
}

int main(){
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << '\n';
}