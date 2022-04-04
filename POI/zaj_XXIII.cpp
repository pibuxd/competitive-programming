// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<int> a, b, pa, pb, w;
vector<vector<int>> dp;
unordered_map<int, int> pr;

int id(int x){
  x %= 2;
  return x;
}

int main(){
  fastio;
  cin >> n >> m;

  a.resize(n+1);
  b.resize(m+1);
  w.resize(m+1);
  pa.resize(n+1);
  pb.resize(m+1);
  dp.resize(2, vector<int>(m+1));
  
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> b[i];

  for(int i = 1; i <= m; i++){
    pb[i] = pr[b[i]];
    pr[b[i]] = i;
  }
  pr.clear();
  for(int i = 1; i <= n; i++){
    pa[i] = pr[a[i]];
    pr[a[i]] = i;
  }

  vector<int> _w(m+1);
  for(int i = 1; i <= n; i++){

    for(int j = 1; j <= m; j++){
      dp[id(i)][j] = max(dp[id(i-1)][j], dp[id(i)][j-1]);

      if(a[i] == b[j]){
        dp[id(i)][j] = max(dp[id(i)][j], w[pb[j]] + (pb[j] > 0 && pa[i] > 0 ? 1 : 0));
        _w[j] = dp[id(i-1)][j-1];
      }
    }

    for(int i = 1; i <= m; i++)
      if(_w[i] != 0)
        w[i] = _w[i], _w[i] = 0;
  }

  cout << 2*dp[id(n)][m];
}

