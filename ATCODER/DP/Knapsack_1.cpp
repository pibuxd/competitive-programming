#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, W;
vector<int> w, v;
vector<vector<int>> dp;

signed main(){
  fastio;
  cin >> n >> W;
  w.resize(n+1);
  v.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  
  dp.resize(n+1, vector<int>(W+1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= W; j++){
      if(j-w[i] >= 0)
        dp[i][j] = dp[i-1][j-w[i]] + v[i];
      dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }
  }

  cout << dp[n][W] << "\n";
}
