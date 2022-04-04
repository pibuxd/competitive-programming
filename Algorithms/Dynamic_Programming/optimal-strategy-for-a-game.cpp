// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<array<int, 2>>> dp;

int main(){
  cin >> n;
  a.resize(n+1);
  dp.resize(n+1, vector<array<int, 2>>(n+1));

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    dp[i][i] = {a[i], 0};
  }
  
  int i = 1, j = 2;
  while(true){
    if(a[i]+dp[i+1][j][1] >= a[j]+dp[i][j-1][1])
      dp[i][j] = {a[i]+dp[i+1][j][1], dp[i+1][j][0]};
    else
      dp[i][j] = {a[j]+dp[i][j-1][1], dp[i][j-1][0]};
    if(i == 1 && j == n)
      break;
    if(j == n)
      j = n-i+2, i = 1;  
    else  
      i++, j++;
  }

  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= n; j++){
  //     cout << dp[i][j][0] << "," << dp[i][j][1] << "\t";
  //   }
  //   cout << "\n";
  // }
  cout << dp[1][n][0];
}