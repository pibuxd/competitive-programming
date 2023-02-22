#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n;
vector<int> dp, o;

signed main(){
  fastio;
  cin >> n;
  dp.resize(n+1, 0);
  o.resize(n+1, 0);

  cin >> o[1] >> o[2];
  dp[1] = o[1], dp[2] = o[2];

  for(int i = 3; i <= n; i++){
    cin >> o[i];
    dp[i] = max(dp[i-2] + o[i], dp[i-3] + o[i] + min(o[i-1], o[i-2]));  
  }

  cout << *max_element(all(dp)) << "\n";
}
