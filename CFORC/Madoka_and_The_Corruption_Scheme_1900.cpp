#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, M = 1e9+7;
vector<int> fac;

void prefac(){
  fac.assign(n+1, 0);
  fac[0] = 1;
  for(int i = 1; i <= n; i++)
    fac[i] = (fac[i-1]*i)%M;
}
  
int quickpow(int a, int b){
  int res = 1;
  while(b > 0){
    if(b % 2 == 1)
      res = (res*a)%M;
    a = (a*a)%M;
    b /= 2;
  }
  return res;
}

int divmod(int a, int b){
  return (a*quickpow(b, M-2))%M;
}

int newton(int a, int b){
  return divmod(fac[a], (fac[b]*fac[a-b])%M);
}

int subt(int a, int b){
  return (a-b+M)%M;
}

signed main(){
  cin >> n >> k;
  
  prefac();
  
  int pow2n = quickpow(2, n);

  if(k >= n){
    cout << pow2n << "\n";
    return 0;
  }
  for(int i = n; i > k; i--){
    pow2n = subt(pow2n, newton(n, i));
  }

  cout << pow2n << "\n";
}
