// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  const int MOD = 1000000007;
  cin >> n;
  
  vector<int> dp(n+1);
  dp[0] = 1;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= 6; j++)
      if(i >= j)
        dp[i] = (dp[i] + dp[i-j]) % MOD;
    
  cout << dp[n];
}