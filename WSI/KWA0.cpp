// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> G, dp;

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  dp.resize(n+1, vector<int>(n+1));

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    for(int x : G[i]){
      for(int y : G[i]){
        if(x == y) continue;
        dp[max(x, y)][min(x, y)] += 1; 
      }
    }
  }

  long long ans = 0;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j) continue;
      ans += ((dp[max(i, j)][min(i, j)] / 2) * (dp[max(i, j)][min(i, j)] / 2 - 1)) / 2;
    }
  }

  //for(int i = 1; i <= n; i++)
  //  for(int j = 1; j <= n; j++)
  //   cout << max(i, j) << ":" << min(i, j) << ",, " << dp[max(i, j)][min(i, j)] << "\n";

  cout << ans / 4; 
}
