// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<int> c, s;
vector<vector<int>> dp;

inline int m(int a){
  a--;
  if(a == -1)
    a = 1;

  return a;
}

int main(){
  fastio;
  cin >> n >> k;
  
  c.resize(n+1); // cena
  s.resize(n+1); // smacznosc

  for(int i = 1; i <= n; i++)
    cin >> c[i] >> s[i];
  
  dp.resize(2, vector<int>(k+1));

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      int _i = i%2;
      int mi = m(_i);
      
      if(j-c[i] < 0)
        dp[_i][j] = dp[mi][j];
      else
        dp[_i][j] = max(dp[mi][j-c[i]] + s[i], dp[mi][j]);
    }
  }

  cout << dp[n%2][k];
}