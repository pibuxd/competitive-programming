#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  const int INF = 1e6+2;
  int n;
  cin >> n;
  vector<int> dp(n+1, INF);
  dp[0] = 0;

  for(int i = 1; i <= n; i++){
    int number = i;

    while(number != 0){
      int digit = number % 10;
      number /= 10;
      if(i >= digit)
        dp[i] = min(dp[i], dp[i-digit] + 1);
    }
  }

  cout << dp[n];
}