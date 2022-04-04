// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Coin change - minimal number of coins to change given sum
// * detect if can't change
#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> c;

int coin_change(){
  vector<int> dp(x+1, -1);
  dp[0] = 0;

  for(int i = 1; i <= x; i++)
    for(int d : c)
      if(d <= i){
        if(dp[i] == -1 && dp[i-d] != -1)
          dp[i] = dp[i-d] + 1;

        else if(dp[i-d] != -1)
          dp[i] = min(dp[i], dp[i-d] + 1);
      }
    
  return dp[x];
}

int main(){
  cin >> n >> x;
  
  while(n--){
    int in;
    cin >> in;
    if(in <= x)
      c.push_back(in);
  }

  cout << coin_change() << "\n";
}