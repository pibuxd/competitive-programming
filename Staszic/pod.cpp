#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, M = 1e9+7, mxc = 1e6;
vector<int> l;

signed main(){
  fastio;
  cin >> n;

  l.resize(mxc+1, 0);
  
  long long dp = 1;
  for(int i = 1; i <= n; i++){
    int c; cin >> c;
    int _l = dp;
    dp = (dp*2 - l[c] + M) % M;
    l[c] = _l;
  }

  cout << dp << "\n";
}
