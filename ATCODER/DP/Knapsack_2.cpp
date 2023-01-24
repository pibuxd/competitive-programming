#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, W, mxv = 1e5;
vector<int> w, v;
vector<vector<int>> dp;

signed main(){
  fastio;
  cin >> n >> W;
  w.resize(n+1);
  v.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  
  dp.resize(n+1, vector<int>(mxv+1, W+1)); // min waga dla ntego przedmiotu dokladnie v
  for(int i = 0; i <= n; i++)
    dp[i][0] = 0;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= mxv; j++){
      if(j >= v[i])
        dp[i][j] = dp[i-1][j-v[i]] + w[i];
      dp[i][j] = min(dp[i][j], dp[i-1][j]);
    }
  
  for(int i = mxv; i >= 0; i--)
    for(int j = 1; j <= n; j++)
      if(dp[j][i] <= W){
        cout << i << "\n";
        return 0;
      }
}
