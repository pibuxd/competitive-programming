#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, m, k, M = 1e9+7, mxn = 2e5;
vector<int> a, fac;

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

void prefac(){
  fac.assign(mxn+1, 0);
  fac[0] = 1;
  for(int i = 1; i <= mxn; i++)
    fac[i] = (fac[i-1]*i)%M;
}

int divmod(int a, int b){
  return (a*quickpow(b, M-2))%M;
}

int newton(int a, int b){
  if(b > a) return 0;
  return divmod(fac[a], (fac[b]*fac[a-b])%M);
}

signed main(){
  fastio;
  int t; cin >> t;
  prefac();

  while(t--){
    cin >> n >> m >> k; 
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }
    sort(all(a));
    int ans = 0;

    for(int i = 1; i <= n; i++){
      int l = i;
      auto it = upper_bound(all(a), a[i]+k);
      it--;
      int r = it-a.begin();
      ans = (ans + newton(r-l, m-1))%M;
    }

    cout << ans << "\n";
  }
}
