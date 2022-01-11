#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<int> s1, s2, pref1, pref2;
vector<vector<int>> dp;

int dp2(int i, int j){
  return pref1[i] + pref2[j] - dp[i][j];
}

int main(){
  fastio;
  cin >> n >> m;

  s1.resize(n+1);
  s2.resize(m+1);
  pref1.resize(n+1);
  pref2.resize(m+1);

  for(int i = 1; i <= n; i++){
    cin >> s1[i];
    pref1[i] = pref1[i-1] + s1[i];
  }
  for(int i = 1; i <= m; i++){
    cin >> s2[i];
    pref2[i] = pref2[i-1] + s2[i];
  }

  dp.resize(n+1, vector<int>(m+1));
  // dp[n][m] - {x, y} wynik dla niewybranych kamieni n i m

  for(int i = 1; i <= n; i++)
    dp[i][0] = dp2(i-1, 0) + s1[i];
  for(int i = 1; i <= m; i++)
    dp[0][i] = dp2(0, i-1) + s2[i];

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++)
      dp[i][j] = max(dp2(i-1, j) + s1[i], dp2(i, j-1) + s2[j]);

  cout << dp[n][m];
}