// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Coin combinations
#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> c;

// combinations can repeat, eg. 2+3+5 isn't 2+5+3
int coin_combinations(){
  vector<int> dp(x+1, 0);
  dp[0] = 1; // eg. when 5 can be combined by only 5
  
  for(int i = 1; i <= x; i++)
    for(int d : c)
      if(d <= i)
        dp[i] += dp[i-d];
  
  return dp[x];
}

// combinations can't repeat, eg. 2+3+5 is equal to 2+5+3
int coin_combinations_distinct(){
  vector<int> dp(x+1, 0);
  dp[0] = 1; // eg. when 5 can be combined by only 5
  
  for(int d : c)
    for(int j = 1; j <= x; j++)
      if(d <= j)
        dp[j] += dp[j-d];

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

  cout << coin_combinations() << "\n";
  cout << coin_combinations_distinct() << "\n";
}