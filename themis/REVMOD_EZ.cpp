#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

pair<int, int> gcdext(int a, int b){
  if(b == 0) return {1, 0};
  auto [x, y] = gcdext(b, a%b);
  return {y, x-y*(a/b)};
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int a, p; cin >> a >> p;
    auto [x, y] = gcdext(a, p);
    if(x >= 0) cout << x << "\n";
    else cout << x+p << "\n";
  }
}
