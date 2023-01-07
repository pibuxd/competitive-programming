#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, M = 998244353;
vector<vector<int>> a, dp;

bool check(int i, int j){
  for(int k = 1; k <= i; k++){
    if(a[k][i] == 1 && k <= j) return false;
    if(a[k][i] == 2 && k > j) return false;
  }
  return true;
}

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1, vector<int>(n+1, 0));
  dp.resize(n+2, vector<int>(n+2, 0));
  for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j++)
      cin >> a[i][j];     
  
  if(a[1][1] != 2) dp[1][0] = 2;

  for(int i = 1; i < n; i++)
    for(int j = 0; j < n; j++)
      for(int k : {j, i})
        if(check(i+1, k))
          dp[i+1][k] = (dp[i+1][k] + dp[i][j]) % M;

  int res = 0;
  for(int i = 0; i <= n; i++)
    res = (res + dp[n][i]) % M;
  cout << res << "\n";
}
