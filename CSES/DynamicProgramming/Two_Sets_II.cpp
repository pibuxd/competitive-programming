#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  const int MOD = 1e9+7;
  cin >> n;

  if(n*(n+1) % 4 != 0){ // than we can't divide
    cout << 0;
    return 0;
  }
  int sum_of_set = n * (n+1) / 4;
  vector<vector<int>> dp(n+1, vector<int>(sum_of_set+1));
  dp[0][0] = 1;

  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= sum_of_set; j++){
      if(i <= j)
        dp[i][j] = (dp[i-1][j] + dp[i-1][j-i]) % MOD;
      else
        dp[i][j] = dp[i-1][j];
    }

  // ! inverse modular arithmetic
  // we want to divide x/y, but x had been moduled by z before -> x % z
  // instead of (x%z) / y
  // we have to do (x%z * ((z+1) / y)) % z
  // eg. divide 10/3, but 10 had been moduled by 6 before
  // bad: 10%6 / 3 = 4/3 
  // good: 10%6 * ((6+1) / 3) % 6 = (10 * 7 / 3) % 6 = 10/3
  cout << ((long long)dp[n][sum_of_set] * ((MOD+1)/2)) % MOD;
}