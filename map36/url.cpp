#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m, k;
vector<vector<array<int, 2>>> G;
vector<vector<int>> dp; // dp[i][j] min dist z 1 do i prz uzyciu j wierzch

void bfs(){
  priority_queue<pair<int, pair<int, int>>> PQ;
  PQ.push({0, {1, 1}}); // {dist, {uzycie wierzch, v}}
  dp[1][1] = 0;

  while(!PQ.empty()){
    auto v = PQ.top();
    PQ.pop();

    if(-v.first > dp[v.second.second][v.second.first])
      continue;

    for(auto x : G[v.second.second]){
      if(-v.first + x[1] < dp[x[0]][v.second.first+1]){
        dp[x[0]][v.second.first+1] = -v.first + x[1];
        PQ.push({v.first - x[1], {v.second.first+1, x[0]}});
      }
    }
  }
}

signed main(){
  fastio;
  cin >> n >> m >> k;

  G.resize(n+1);
  dp.resize(n+1, vector<int>(n+1, LONG_LONG_MAX));

  for(int i = 1; i <= m; i++){
    int a, b, t; cin >> a >> b >> t;
    G[a].push_back({b, t});
  }

  bfs();

  int mx = 1;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      if(dp[i][j] <= k){
        mx = max(mx, j);
      }
    }
  
  cout << mx << "\n";
}