// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MX (int)(1e10)

vector<pair<int, int>> factors(int n, int k){
  vector<pair<int, int>> ret;
  for(int i = 2; i * i <= n; i++){
    int cnt = 0;
    while(n % i == 0){
      cnt++;
      n /= i;
    }
    if(cnt % k)
      ret.push_back({i, cnt % k});
  }
  if(n > 1)
    ret.push_back({n, 1});
  return ret;
}

vector<pair<int, int>> _factors(const vector<pair<int, int>> &fac, int n, int k){
  vector<pair<int, int>> ret;
  
  for(auto f : fac)
    ret.push_back({f.first, k-f.second});

  return ret;
}

signed main(){
  fastio;
  int n, k; cin >> n >> k;

  vector<int> a(n+1);
  vector<vector<pair<int, int>>> fac(n+1);
  map<vector<pair<int, int>>, int> zlicz;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    fac[i] = factors(a[i], k);
    zlicz[fac[i]]++;
  }
  
  int ans = 0;
  for(int i = 1; i <= n; i++){
    zlicz[fac[i]]--;
    ans += zlicz[_factors(fac[i], a[i], k)];
  }

  cout << ans;
}