#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<int>> G;
vector<int> val, dp1, dp2; // 1 - bez, 2 - z
vector<bool> use;

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;

    dfs(x, v);
    // dp1[v] += min(dp1[x] + val[x], dp2[x]);
    
    // dp1[v] += dp2[x];
    if(dp1[x] + val[x] <= dp2[x]){
      dp1[v] += dp1[x] + val[x];
    }
    else{
      dp1[v] += dp2[x];
    }
    
    // dp2[v] += min(dp1[x], dp2[x]); 
    if(dp1[x] <= dp2[x]){
      dp2[v] += dp1[x];
    }
    else{
      dp2[v] += dp2[x];
    }
  }
}

void dfs2(int v, int p){
  if(dp1[v] <= dp2[v] && dp1[v] > 0){
    use[v] = false;

    for(int x : G[v]){
      if(x == p) continue;
      dfs2(x, v);
    }
  }
  else{
    for(int x : G[v]){
      if(x == p) continue;
      dfs2(x, v);
    }
  }
}

void solve(){
  cin >> n;
  G.assign(n+1, vector<int>());
  val.assign(n+1, 0);
  dp1.assign(n+1, 0);
  dp2.assign(n+1, 0);
  use.assign(n+1, true);

  for(int i = 1; i <= n; i++){
    cin >> val[i];
    dp2[i] = val[i];
  }

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfs(1, -1);
  dfs2(1, -1);

  cout << min(dp1[1], dp2[1]) << "\n";
  for(int i = 1; i <= n; i++)
    cout << use[i];
  cout << "\n";
}

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--)
    solve();
}