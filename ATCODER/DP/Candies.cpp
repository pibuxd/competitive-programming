// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define M (int)(1e9+7)

int n, k;
vector<int> a, pref;
vector<vector<int>> dp;

int main(){
  fastio;
  cin >> n >> k;
  a.resize(n+1);
  pref.resize(k+1);
  dp.resize(n+1, vector<int>(k+1));

  dp[0][0] = 1;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  for(int i = 1; i <= n; i++){
    pref[0] = dp[i-1][0];

    for(int j = 1; j <= k; j++)
      pref[j] = (pref[j-1] + dp[i-1][j]) % M;

    for(int j = 0; j <= k; j++){
      if(j-a[i]-1 >= 0)
        dp[i][j] = (pref[j] - pref[j-a[i]-1] + M) % M;
      else
        dp[i][j] = pref[j];
    }
  }

  cout << dp[n][k];
}