#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, M = 998244353;
vector<vector<int>> G;
vector<vector<vector<int>>> dp;
vector<int> out, sil, par, sub;

void dfst(int v, int p){
  par[v] = p;
  sub[v] = 1;

  for(int x : G[v]){
    if(x == p) continue;
    dfst(x, v);
    sub[v] += sub[x];
    out[v] = (out[v] * out[x]) % M;
  }
  out[v] = (out[v] * sil[G[v].size()-1]) % M;
}

signed main(){
  //fastio;
  cout << "\n";
  cin >> n;
  G.resize(n+1);
  sub.resize(n+1);
  par.resize(n+1);
  out.resize(n+1, 1);
  sil.resize(n+1);
  dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
  
  sil[0] = 1;
  for(int i = 1; i <= n; i++)
    sil[i] = (sil[i-1] * i) % M;

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  G[1].push_back(0);
  dfst(1, 0);
  dp[1][1][1] = out[1];
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      dp[i][j][0] = out[1];

  for(int j = 2; j <= n; j++){
    for(int i = 1; i <= n; i++){
      // k = 0
      int pa = par[i];
      int z = 0;
      z = dp[pa][j-1][0] / sil[G[pa].size()-1] * sil[max((int)0, (int)G[pa].size()-2)]; 
      //int z = dp[pa][j-1][0] / sil[G[pa].size()-1] * sil[max((int)0, (int)(G[pa].size())-(int)2)];
      dp[i][j][1] = z;
      for(int k = 2; k <= (int)G[pa].size()-1; k++){
        //cout << i << ", " << j << ", " << k << ", " << G[pa].size()-1 << "\n";
        z = 0;
        for(int x : G[pa]){
          if(x == i || x == par[pa]) continue;
          int y = j-sub[x];
          if(y < 1) continue;

          z += dp[x][y][k-1] / sil[G[pa].size() - k] * sil[G[pa].size() - k - 1];
        }

        dp[i][j][k] = (z) % M;
      }
    }
  }
  
  
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int d = 0;
      for(int k = 0; k <= n; k++)
        d = dp[i][j][k];
      cout << d << " ";
    }
    cout << "\n";
  }
}
