#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

pair<int, int> gcdext(int a, int b, int c){
  if(b == 0){
    if(c%a == 0) return {c/a, 0};
    else return {0, 0};
  }

  auto [x, y] = gcdext(b, a%b, c);
  if(!x && !y) return {0, 0};

  return {y, x-y*(a/b)};
}

signed main(){
  fastio;
  int a, b, c; cin >> a >> b >> c;
  if(c == 0){
    cout << "0 0\n";
    return 0;
  }
  auto [x, y] = gcdext(a, b, c);
  if(!x && !y)
    cout << "NIE\n";
  else
    cout << x << " " << y << "\n";
}
