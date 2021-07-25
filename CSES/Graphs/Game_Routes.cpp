// * Topological Sort
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9+7;
int n, m;
vector<vector<int>> G;
vector<int> ind, dp;
vector<bool> on_path;

void dfs(int v){
  for(int x : G[v]){
    if(!on_path[x]){
      on_path[x] = true;
      dfs(x);
    }
  }
}

void top_sort(){
  queue<int> Q;
  for(int i = 1; i <= n; i++)
    if(!ind[i]){
      dp[i] = 1;
      Q.push(i);
    }
  
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : G[v]){
      if(on_path[v])
        dp[x] = (dp[x] + dp[v]) % MOD;
      ind[x]--;
      if(!ind[x]){
        Q.push(x);
      }
    }
  }
}


int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  ind.resize(n+1);
  dp.resize(n+1);
  on_path.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    ind[b]++;
  }
  dp[1] = 1;
  on_path[1] = true;
  dfs(1);
  top_sort();

  if(!on_path[n])
    dp[n] = 0;
  cout << dp[n];
}