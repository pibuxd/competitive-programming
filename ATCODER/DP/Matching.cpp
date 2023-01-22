#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, n1, M = 1e9+7;
vector<vector<int>> v;
vector<int> dp;

int main(){
  fastio;
  cin >> n;
  n1 = 1<<n;
  v.resize(n+1, vector<int>(n+1));
  dp.resize(1<<n, 0);

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      cin >> v[i][j];

  dp[0] = 1; 
  for(int mask = 0; mask < (1<<n)-1; mask++){
    int a = __builtin_popcount(mask);
    for(int b = 0; b < n; b++){
      if(v[a+1][b+1] && !(mask & (1<<b)))
        dp[mask^(1<<b)] = (dp[mask] + dp[mask^(1<<b)]) % M;
    }
  }

  cout << dp[(1<<n)-1] << "\n";
}
