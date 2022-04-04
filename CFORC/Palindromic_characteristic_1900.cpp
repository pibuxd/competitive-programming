// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * DP on strings
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  string s;
  cin >> s;
  int n = s.size();

  vector<vector<int>> dp(n+1, vector<int>(n+1));
  
  for(int len = 1; len <= n; len++)
    for(int l = 0; l + len - 1 < n; l++){
      int r = l + len;
    
      if(len == 1){
        dp[l][r] = 1;
        continue;
      } else if(len == 2){
        if(s[l] == s[r - 1])
          dp[l][r] = 2;
        else
          dp[l][r] = 0;
        continue;
      }
            
      if(s[l] != s[r - 1] || !dp[l + 1][r - 1]){
        continue;
      }
      
      dp[l][r] = 1;
      int m = (l+r)/2;

      if(len & 1){
        if(dp[l][m] && dp[m+1][r])
          dp[l][r] = dp[l][m] + 1;
      }
      else{
        if(dp[l][m] && dp[m][r])
          dp[l][r] = dp[l][m] + 1;
      }
    }

  vector<int> ans(n+1);
  for(int len = 1; len <= n; len++){
    for(int l = 0; l < n - len + 1; l++){
      ans[dp[l][l + len]]++;
    }
  }
  
  for(int i = n - 1; i >= 1; i--){
    ans[i] += ans[i + 1];
  }
  
  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}