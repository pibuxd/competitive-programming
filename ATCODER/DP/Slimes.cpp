// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * DP on segments + prefix sums
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define INF (int)(1e16)

int n;
vector<int> a, pref;
vector<vector<int>> d;

int sum(int l, int r){
  return pref[r] - pref[l-1];
}

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  pref.resize(n+1);
  d.resize(n+1, vector<int>(n+1, INF));

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    pref[i] = pref[i-1] + a[i];
    d[i][i] = 0;
  }

  for(int len = 1; len <= n; len++){
    for(int l = 1; l+len <= n; l++){
      int r = l+len;

      for(int i = l; i <= r-1; i++){
        int val = 0;
        val += sum(l, i) + sum(i+1, r);
        val += d[l][i] + d[i+1][r];

        d[l][r] = min(d[l][r], val);
      }
    }
  }

  cout << d[1][n];
}