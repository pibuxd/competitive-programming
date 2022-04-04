// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int minimum_edit_distance(string &a, string &b){
  int as = a.size(), bs = b.size();
  vector<vector<int>> dp(as+1, vector<int>(bs+1));

  for(int i = 0; i <= as; i++)
    dp[i][0] = i;
  for(int i = 0; i <= bs; i++)
    dp[0][i] = i;

  for(int i = 1; i <= as; i++)
    for(int j = 1; j <= bs; j++){
      if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
    }
  
  return dp[as][bs];
}

int main(){
  fastio;
  string a, b;
  cin >> a >> b;
  cout << minimum_edit_distance(a, b);
}