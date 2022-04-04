// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Prime factorization
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

vector<pair<int, int>> factors(int n){
  vector<pair<int, int>> ret;
  for(int i = 2; i * i <= n; i++){
    int cnt = 0;
    while(n % i == 0){
      cnt++;
      n /= i;
    }
    if(cnt)
      ret.push_back({i, cnt});   
  }
  if(n > 1)
    ret.push_back({n, 1});
  return ret;
}

signed main(){
  fastio;
  int n; cin >> n;

  auto fac = factors(n);

  // for(auto i : fac)
  //   cout << i.first << ", " << i.second << "\n";

  int ans = 0;

  for(auto f : fac){
    int cnt = f.second;
    int pi = 1;

    while(cnt - pi >= 0){
      ans++;
      cnt -= pi;
      pi++;
    }
  }

  cout << ans;
}