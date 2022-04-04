// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Prefix sums
#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<int> a, dp;

void prefix(){
  dp[0] = 0;
  for(int i = 1; i <= n; i++)
    dp[i] = dp[i-1] + a[i];
}

int main(){
  cin >> n >> q;
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
    
  dp.resize(n+1);
  prefix();
  
  while(q--){
    int a, b;
    cin >> a >> b;
    int ans = dp[b] - dp[a-1];
    cout << ans << "\n";
  }
}