#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
string s, t;
vector<vector<int>> dp;

int main(){
  fastio;
  cin >> s >> t;
  n = s.size(), m = t.size();
  dp.resize(n+1, vector<int>(m+1, 0));

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1] + (s[i-1] == t[j-1])});
  
  string res;
  int i = n, j = m;
  while(dp[i][j] > 0){
    int mx = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1] + (s[i-1] == t[j-1])});
    if(dp[i-1][j] == mx)
      i--;
    else if(dp[i][j-1] == mx)
      j--;
    else{
      res += s[i-1];
      i--, j--;
    }
  }

  reverse(res.begin(), res.end());
  cout << res << "\n";
}
