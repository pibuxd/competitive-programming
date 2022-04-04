// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Coin change
// detect if can't change
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)


int main(){
  fastio;
  int n, x;
  cin >> n >> x;
  vector<int> c;
  
  while(n--){
    int in;
    cin >> in;
    if(in <= x)
      c.push_back(in);
  }

  vector<int> dp(x+1, -1);
  dp[0] = 0;

  for(int i = 1; i <= x; i++){
    for(int d : c){
      if(d <= i){
        if(dp[i] == -1 && dp[i-d] != -1)
          dp[i] = dp[i-d] + 1;

        else if(dp[i-d] != -1)
          dp[i] = min(dp[i], dp[i-d] + 1);
      }
    }
  }

  cout << dp[x];
}