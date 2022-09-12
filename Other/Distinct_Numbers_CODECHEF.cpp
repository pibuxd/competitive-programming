#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, K, M = 1e9+7;

// faktoryzacja
vector<array<int, 2>> factors(int n){
  vector<array<int, 2>> fac;

  int sqn = sqrt(N);
  for(int i = 2; i <= sqn; i++){
    int cnt = 0;
    while(n % i == 0)
      n /= i, cnt++;
    if(cnt)
      fac.push_back({i, cnt});
  }
  if(n != 1)
    fac.push_back({n, 1});
  return fac;
}

// szybkie potegowanie
int quickpow(int a, int b, int mod){
  int res = 1;
  while(b > 0){
    if(b % 2 == 1)
      res = res * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return res;
}

// inwersja modulo (dzielenie modulo)
int divmod(int a, int b){
  return a * quickpow(b, M-2, M) % M;
}

// suma ciagu geometrycznego
int sumgeo(int a1, int q, int n){
  return a1 * divmod(quickpow(q, n, M) - 1, q - 1) % M;
}

int solve(){
  auto fac = factors(N);
  int sum = 1;

  for(auto &f : fac){
    int newK = f[1] * (quickpow(2, K, M-1) - 1) % (M-1);
    sum = sum * sumgeo(1, f[0], newK+1) % M;
  }
  return (sum * N) % M;
}

signed main(){
  int t; cin >> t;
  while(t--){
    cin >> N >> K;
    cout << solve() << "\n";
  }
}
