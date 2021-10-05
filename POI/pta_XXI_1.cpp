#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, INF = INT_MAX;
vector<int> t;

int solve(){
  vector<int> dp(n+1);
  multiset<int> S0, S1;

  int val0 = 0, val1 = 1;
  int x0 = 0, x1 = 0;
  for(int i = 2; i <= k+1 && i <= n; i++){
    if(t[i] >= t[1]){
      dp[i] = 1, x1++;
      S1.insert(-t[i]);
    }
    else{
      dp[i] = 0, x0++;
      S0.insert(-t[i]);
    }
  }

  int l = 1+k + 1;

  while(l <= n){
    if(x0 == 0){
      swap(S0, S1);
      val0 = val1, val1++;
      x0 = x1, x1 = 0;
    }

    int hi = -(*S0.begin());
    if(hi <= t[l])
      dp[l] = val0 + 1;
    else
      dp[l] = val0;

    if(dp[l-k] == val0){
      auto it_first = S0.find(-t[l-k]);
      S0.erase(it_first);
      x0--;
      if(x0 == 0){
        swap(S0, S1);
        val0 = val1, val1++;
        x0 = x1, x1 = 0;
      }
    }
    else{
      auto it_first = S1.find(-t[l-k]);
      S1.erase(it_first);
      x1--;
    }

    if(dp[l] == val0){
      S0.insert(-t[l]);
      x0++;
    }
    else{
      val1 = dp[l];
      S1.insert(-t[l]);
      x1++;
    }
    if(val1 < val0){
      swap(S0, S1);
      swap(val0, val1);
      swap(x0, x1);
    }
    // cout << l << ": " << dp[l] << "; x0 = " << x0 << ", val0 = " << val0 <<
    //       ", x1 = " << x1 << ", val1 = " << val1 << ", hi = " << hi << "\n";
    l++;
  }

  // cout << "\n";
  return dp[n];
}

int main(){
  fastio;
  cin >> n;
  t.resize(n+1);

  for(int i = 1; i <= n; i++){
    cin >> t[i];
  }

  int q;
  cin >> q;
  while(q--){
    cin >> k;
    cout << solve() << "\n";
  }
}