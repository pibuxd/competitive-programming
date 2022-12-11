#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, k, M = 1e9+7, ans;
vector<int> pw, silnia;

int pot(int a, int b){
  int res = 1;
  while(b > 0){
    if(b % 2 == 1)
      res = (res * a) % M;
    a = (a * a) % M;
    b /= 2;
  }
  return res;
}

int inv(int x){
  return pot(x, M-2);
}

int C(int a, int b){
  if(b > a) return 0;
  return (silnia[a] * inv((silnia[b]*silnia[a-b])%M)) % M;
}

int pwf(int x){
  if(x < 0) return 0;
  return pw[x];
}

signed main(){
  fastio;
  cin >> n >> k;
  
  pw.assign(n+1, 0);
  silnia.assign(n+1, 0);
  pw[0] = 1;
  for(int i = 1; i <= n; i++)
    pw[i] = (pw[i-1] * 3) % M;
  silnia[0] = 1;
  for(int i = 1; i <= n; i++)
    silnia[i] = (silnia[i-1] * i) % M;
  if(k == 0){ cout << pw[n] << "\n"; return 0;}
  ans = 0;
  for(int s = 1; s <= k; s++){
    ans += ((pwf(n-2*s) * C(n-k, s))%M * C(k-1, s-1))%M;
    ans += ((pwf(n-2*s+1) * C(n-k, s-1))%M * C(k-1, s-1))%M;
    ans %= M;
  }
  cout << ans << "\n";
}
