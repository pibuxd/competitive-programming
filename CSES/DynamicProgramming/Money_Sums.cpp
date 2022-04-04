// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;

  int max_sum = 0;
  vector<int> coins(n+1);
  for(int i = 1; i <= n; i++){
    cin >> coins[i];
    max_sum += coins[i];
  }

  vector<vector<bool>> dp(n+1, vector<bool>(max_sum+1));
  vector<int> possible_sums;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= max_sum; j++){
      if(coins[i] <= j){
        if(dp[i-1][j])
          dp[i][j] = true;
        if(dp[i-1][j-coins[i]] || j == coins[i]){
          if(!dp[i][j])
            possible_sums.push_back(j);
          dp[i][j] = true;
        }
      } else{
        dp[i][j] = dp[i-1][j];
      }
    }
  
  sort(possible_sums.begin(), possible_sums.end());

  cout << possible_sums.size() << "\n";
  for(int &x : possible_sums)
    cout << x << " ";
}