// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<int> x, y;

int solve(){
  int pio = 0;
  cin >> n >> m;
  x.assign(m+1, 0);
  y.assign(n+1, 0);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      char c; cin >> c;
      if(c == '.') continue;
      pio++;
      x[j]++;
      y[i]++;
    }
  }

  int mxX = 0, mxY = 0;

  for(int i = 1; i <= n; i++){
    mxX = max(mxX, x[i]);
    mxY = max(mxY, y[i]);
    
  }

  int ans;
  ans = pio - mxX + pio - mxY;
  return ans;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    cout << solve() << "\n";
  }
}