#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, q, mxy = 2*1e6;
vector<int> bit;

void add(int idx){
  for(; idx <= mxy; idx += idx & -idx)
    bit[idx]++;
}

int sum(int idx){
  int res = 0;
  for(; idx > 0; idx -= idx & -idx)
    res += bit[idx];
  return res;
}

signed main(){
  fastio;
  cin >> n >> q;

  vector<pair<int, int>> ludzie;
  vector<pair<pair<int, int>, int>> straz;

  for(int i = 1; i <= n; i++){
    int x, y; cin >> x >> y;
    int X = x-y, Y = x+y;
    ludzie.push_back({X, Y});
  }
  for(int i = 1; i <= q; i++){
    int x, y; cin >> x >> y;
    int X = x-y, Y = x+y;
    straz.push_back({{X, Y}, i});
  }
  
  bit.assign(mxy+1, 0);
  sort(all(ludzie));
  sort(all(straz));
  auto l = ludzie.begin();
  vector<int> ans(q+1);

  for(auto s : straz){
    while(l != ludzie.end() && l->first <= s.first.first){
      add(l->second);
      l++;
    }

    ans[s.second] = sum(s.first.second);
  }

  for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
