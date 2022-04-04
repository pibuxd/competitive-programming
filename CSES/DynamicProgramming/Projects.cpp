// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int main(){
  fastio;
  int n;
  cin >> n;
  array<int, 3> a[n];

  for(auto &x : a)
    cin >> x[1] >> x[0] >> x[2]; // to sort by ending

  sort(a, a+n);
  set<array<ll, 2>> dp;
  dp.insert({0, 0});
  ll max_dp = 0;

  for(auto &x : a){
    auto it = dp.lower_bound({x[1]});
    it--;
    max_dp = max(max_dp, (*it)[1] + x[2]);
    dp.insert({x[0], max_dp});
  }

  cout << max_dp;
}