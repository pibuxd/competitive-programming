#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fl long double

fl n, n2;
vector<vector<vector<fl>>> dp; // kropka, koniec weza, palka
vector<vector<vector<bool>>> vis;

fl foo(fl kropki, fl konce, fl palki){
  if(vis[kropki][konce][palki]) return dp[kropki][konce][palki];
  vis[kropki][konce][palki] = true;
  if(2*palki+konce+kropki < 2) return 0.0;
  if(2*palki + konce + kropki == 2 && palki == 1) return 0.0;
  fl DP = 1.0;
  fl wr = 0.0;
  wr += konce*(konce-1);
  wr += palki*2*kropki*2;
  wr += kropki * (kropki-1);
  wr += palki * 2 * (2*palki-2);
  wr += konce * kropki * 2;
  wr += konce * 2 * palki * 2;
  wr = 1.0 - wr/n2;
  if(konce >= 2){
    fl p = konce*(konce-1)/n2;
    DP += foo(kropki, konce-2, palki) * p;
  }
  if(palki && kropki){
    fl p = (palki*2*kropki*2)/n2;
    DP += foo(kropki-1, konce+2, palki-1) * p;
  }
  if(kropki >= 2){
    fl p = (kropki*(kropki-1))/n2;
    DP += foo(kropki-2, konce, palki+1) * p;
  }
  if(palki >= 2){ 
    fl p = (palki*2*(2*palki-2))/n2;
    DP += foo(kropki, konce+2, palki-2) * p;
  }
  if(kropki && konce){
    fl p = (konce*kropki*2)/n2;
    DP += foo(kropki-1, konce, palki) * p;
  }
  if(palki && konce){
    fl p = (konce*2*palki*2)/n2;
    DP += foo(kropki, konce, palki-1) * p;
  }
  DP /= 1.0-wr;
  dp[kropki][konce][palki] = DP;
  return DP;
}

signed main(){
  fastio;
  cin >> n;
  n2 = n*n;
  dp.resize(n+1, vector<vector<fl>>(n+1, vector<fl>(n+1, 0.0)));
  vis.resize(n+1, vector<vector<bool>>(n+1, vector<bool>(n+1, false)));
  cout << fixed << setprecision(12) << foo(n, 0, 0) << "\n";
}
