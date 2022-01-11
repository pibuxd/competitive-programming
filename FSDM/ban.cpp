#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF 1000000

int n, k;
vector<int> b, c;
vector<vector<int>> dp;

int main(){
  fastio;
  cin >> n;
  b.resize(n+1);
  c.resize(n+1);

  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++) cin >> c[i];

  cin >> k;

  dp.resize(k+1, vector<int>(n+1));
  // w dp[k][0] - wynik, w i->n dp[k][i] ile do dyspozycji

  dp[0] = c;

  for(int i = 1; i <= k; i++){
    dp[i] = [i]()->vector<int>{
      
      int to_del = 0, mn_del = INF;
      for(int j = 1; j <= n; j++){
        if(i-b[j] >= 0 && dp[i-b[j]][j] > 0){
          if(dp[i-b[j]][0] == 0 && b[j] == i)
            to_del = j, mn_del = dp[i-b[j]][0];
          else if(dp[i-b[j]][0] != 0 && mn_del > dp[i-b[j]][0])
            to_del = j, mn_del = dp[i-b[j]][0];
        }
      }

      if(to_del == 0)
        return dp[0];  

      vector<int> ans = dp[i-b[to_del]];
      ans[to_del]--;
      ans[0]++;
      return ans;
    }();
  }

  cout << dp[k][0] << "\n";
  for(int i = 1; i <= n; i++)
    cout << c[i] - dp[k][i] << " ";
}