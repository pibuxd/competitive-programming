// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * 2D prefix sums
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<vector<bool>> a;
vector<vector<int>> dp;

void prefix_2d(){
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
}

int main(){
  fastio;
  cin >> n >> q;
  a.resize(n+1, vector<bool>(n+1));
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      char c;
      cin >> c;
      if(c == '*')
        a[i][j] = 1;
    }

  dp.resize(n+1, vector<int>(n+1));
  prefix_2d();

  while(q--){
    int x1, x2, y1, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    int ans = dp[y2][x2] - dp[y1-1][x2] - dp[y2][x1-1] + dp[y1-1][x1-1];
    cout << ans << "\n";
  }
}