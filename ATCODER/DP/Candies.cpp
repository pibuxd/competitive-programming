#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, k, M = 1e9+7;
vector<int> dp, pref;

signed main(){
  fastio;
  cin >> n >> k;
  
  dp.resize(k+1, 0);
  pref.resize(k+1, 0);
  dp[0] = 1;

  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    pref[0] = dp[0];
    for(int t = 1; t <= k; t++)
      pref[t] = (pref[t-1] + dp[t]) % M;
    
    dp.assign(k+1, 0);
    for(int j = 0; j <= k; j++)
      if(j-a-1 >= 0)
        dp[j] = (pref[j] - pref[j-a-1] + M) % M;
      else
        dp[j] = pref[j];
  }

  cout << dp[k] << "\n";
}
