#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ans;
vector<array<int, 2>> v;
multiset<int> s;

int main(){
  fastio;
  cin >> n >> k;
  v.resize(n);

  for(auto &x : v){
    cin >> x[1] >> x[0];
  }

  sort(v.begin(), v.end());
  
  for(int i = 0; i < k; i++){
    s.insert(i);
  }

  ans = 0;

  for(auto x : v){
    auto it = s.upper_bound(x[1]);
    if(it == s.begin()) continue;
    it--;
    s.erase(it);
    s.insert(x[0]);
    ans++;
  }
  
  cout << ans;
}