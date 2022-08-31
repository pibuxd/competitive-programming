#include <bits/stdc++.h>
using namespace std;
#define int long long

int M = 1e9+7, mxn = 1e6;
vector<int> fac;

// computes a^b modulo M in O(log n) time
int quickpow(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans = (ans * a)%M;
    a = (a*a)%M;
    b /= 2;
  }
  return ans;
}

// divide a/b with modulo using modular inverse int O(log n)
int divmod(int a, int b){
  return (a * quickpow(b, M-2))%M;
}

// Computes nCr mod M
int newton(int a, int b){
  int res = fac[a];
  res = divmod(res, fac[b]);
  res = divmod(res, fac[a-b]);
  return res;
}

// Precomputes n! from 0 to MAXN
void factorial(){
  fac.assign(mxn+1, 0);
  fac[0] = 1;
  for(int i = 1; i <= mxn; i++)
    fac[i] = (fac[i-1] * i)%M;
}
