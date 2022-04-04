// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<array<int, 2>> v;

int main(){
  fastio;
  cin >> n;
  v.resize(n);

  for(auto &x : v){
    cin >> x[0] >> x[1];
  }

  sort(v.begin(), v.end());
  
  long long ans = 0, time = 0;
  for(auto x : v){
    time += x[0];
    ans += x[1] - time;
  }
  
  cout << ans;
}