// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Ways to calculate n'th Fibonacci numbers
#include <bits/stdc++.h>
using namespace std;

int fib_math(int n){
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5)); 
}

int fib_dp(int n){
  vector<int> f(n+1);
  f[0] = 0;
  f[1] = 1;

  for(int i = 2; i <= n; i++)
    f[i] = f[i-1] + f[i-2];
  return f[n];
}

int fib_recursion(int n){
  if(n <= 1)
    return n;
  return fib_recursion(n-1) + fib_recursion(n-2);
}

int main(){
  int n;
  cin >> n;
  cout << fib_math(n);
  cout << fib_dp(n);
  cout << fib_recursion(n);
}