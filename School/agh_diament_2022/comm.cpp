#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int l, n;
vector<array<int, 3>> a;
set<array<int, 2>> dp;

int main(){
  fastio;
  cin >> l >> n;

  for(int i = 1; i <= n; i++){
    int x, y, z;
    cin >> x >> y >> z;

    int profit = y-x-z;
    if(profit > 0 && y <= l){
      a.push_back({y, x, profit});
    }
  }

  sort(a.begin(), a.end());
  set<array<int, 2>> dp;
  dp.insert({0, 0});
  int max_dp = 0;

  for(auto &x : a){
    auto it = dp.lower_bound({x[1]});
    it--;
    max_dp = max(max_dp, (*it)[1] + x[2]);
    dp.insert({x[0], max_dp});
  }

  cout << l - max_dp;
}