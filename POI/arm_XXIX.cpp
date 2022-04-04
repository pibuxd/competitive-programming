// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// autor: Piotr Bublik
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define dint long double

const int INF = 1e18;
int n, a, b, ans;

int _ceil(int x, int y){
  if(x % y > 0) return x/y + 1;
  return x/y;
}

dint log_3(dint x) {
  return (dint)(log(x) / log(3));
}

int solve1(){
  int a1 = 3 * ceil(log_3(n));
  int a2 = 2 + 3 * ceil(log_3(n/2));
  int a3 = 4 + 3 * ceil(log_3(n/4));
  return min({a1, a2, a3});
}

int koszt(array<int, 3> x){
  if(x == array<int, 3>{0, 0, 0}) return INF;
  return a*x[0] + b*x[1];
}

int solve2(){
  vector<array<int, 3>> dp(n+2); // dp[i] = {ile_scanow, ile_kopi, wartosc}
  dp[1] = {0, 0, 1};
  dp[2] = {1, 1, 2};
  dp[3] = {1, 2, 3};

  for(int i = 4; i <= n+1; i++){
    for(int j = 1; j <= i-1; j++){
      
      int razy = _ceil(i, dp[j][2]);
      int koj = koszt({dp[j][0]+1, dp[j][1]+razy-1, dp[j][2]*(razy)});
      int koi = koszt(dp[i]);
      if(koj <= koi){
        dp[i] = {dp[j][0]+1, dp[j][1]+razy-1, dp[j][2]*(razy)};
      }
    }
  }

  return koszt(dp[n+1]);
}

void xor_test(int _n, int _a, int _b){
  int xo = 0;
  for(int i = 1; i <= _n; i++){
    for(int j = 1; j <= _a; j++){
      for(int k = 1; k <= _b; k++){
        n = i, a = j, b = k;
        xo ^= solve2();
      }
    }
  }
  cout << xo << "\n";
}

void __solve(){
  cin >> n >> a >> b;

  if(n <= 1000){
    cout << solve2();
  }
  else if(a == 1 && b == 1){
    cout << solve1();
  }
}

signed main(){
  fastio;

  // xor_test(100, 25, 25);

  __solve();
}