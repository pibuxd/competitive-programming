#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

pair<int, int> gcdext(int a, int b){
  if(b == 0){
    if(1%a == 0) return {1/a, 0};
    else return {0, 0};
  }

  auto [x, y] = gcdext(b, a%b);
  if(!x && !y) return {0, 0};

  return {y, x-y*(a/b)};
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int a, b; cin >> a >> b;
    auto [x, y] = gcdext(a, b);
    if(!x && !y)
      cout << "NIESTETY\n";
    else
      cout << abs(x) << " " << abs(y) << "\n";
  }
}
