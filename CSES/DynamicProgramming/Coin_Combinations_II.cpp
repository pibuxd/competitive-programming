#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  const int MOD = 1e9+7;
  int n, x;
  cin >> n >> x;
  vector<int> c;
  
  while(n--){
    int in;
    cin >> in;
    if(in <= x)
      c.push_back(in);
  }

  vector<int> dp(x+1, 0);
  dp[0] = 1; // eg. when 5 can be combined by only 5
  
  for(int i : c)
    for(int j = 1; j <= x; j++)
      if(i <= j)
        dp[j] = (dp[j] + dp[j-i]) % MOD;
  

  cout << dp[x];
}