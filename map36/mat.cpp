#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int k, p, M = 1e9+7, mxkp = 1e6;
vector<int> primes, silnia;

void sieve(int n){
  vector<bool> isprime(n+1, true);
  isprime[0] = isprime[1] = false;
  for(int i = 2; i <= n; i++){
    if(isprime[i])
      for(int j = i*i; j <= n; j += i)
        isprime[j] = false;
  }
  for(int i = 2; i <= n; i++)
    if(isprime[i])
      primes.push_back(i);
}

void presilnia(int n){
  silnia.assign(n+1, 0);
  silnia[1] = 1;
  for(int i = 2; i <= n; i++)
    silnia[i] = (silnia[i-1]*i)%M;
}

int quickpow(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans = (ans*a)%M, b--;
    a = (a*a)%M;
    b /= 2;
  }
  return ans;
}

int divmod(int a, int b){
  return (a*quickpow(b, M-2))%M;
}

int newtonsym(int _n, int _k){
  if(_k == 0) return 1;
  return divmod(silnia[_n], (silnia[_n-_k]*silnia[_k])%M);
}

int alphasum(int x){
  int sum = 0;
  for(int i : primes){
    while(x % i == 0)
      sum++, x /= i;
  }
  return sum;
}

signed main(){
  fastio;
  cin >> k >> p;

  sieve(mxkp+1);
  presilnia(mxkp+1);
  int LP = upper_bound(all(primes), p) - primes.begin();
  cout << newtonsym(alphasum(k)+LP-1, LP-1) << "\n";
}
