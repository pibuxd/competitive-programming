#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n, k, ans;
vector<vector<long long>> G, dp;

void dfs(long long v, long long p){
  dp[v][0] = 1;

  for(long long x : G[v]){
    if(x == p) continue;

    dfs(x, v);

    for(int i = 1; i <= k; i++)
      ans += dp[x][i-1]*dp[v][k-i];

    for(long long i = 1; i <= k; i++)
      dp[v][i] += dp[x][i-1];
  }
}

int main(){
  fastio;
  cin >> n >> k;
  G.resize(n+1);
  dp.resize(n+1, vector<long long>(k+1));

  for(long long i = 1; i <= n-1; i++){
    long long a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfs(1, 0);

  cout << ans;
}