#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, k;
  cin >> n >> k;
  int sq = 300;
  vector<vector<int>> dp(n+sq+2, vector<int>(sq+1));
  vector<int> ans(n+sq+2);

  while(k--){
    int a, l, d;
    cin >> a >> l >> d;

    if(d > sq)
      for(int i = 0; i < l; i++)
        ans[a + i*d]++;
    else
      dp[a][d]++, dp[a+l*d][d]--;
  }

  for(int i = 1; i <= sq; i++)
    for(int j = i; j <= n; j++)
      dp[j][i] += dp[j-i][i];

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= sq; j++)
      ans[i] += dp[i][j];
    cout << ans[i] << " ";
  }
}
