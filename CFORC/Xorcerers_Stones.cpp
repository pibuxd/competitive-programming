#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, K;
vector<int> a, x;
vector<vector<int>> G, dp;

void dfs(int v, int p){
  int X = a[v];
  for(int x : G[v]){
    if(x == p) continue;
    X ^= dfs(x, v);
  }
  return X;
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  x.resize(n+1);
  G.resize(n+1);
  dp.resize(n+1, vector<int>(K+1, 0));

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 2; i <= n; i++){
    int p; cin >> p;
    G[i].push_back(p);
    G[p].push_back(i);
  }
  
  K = 31;
  dfs(1, 0);
  
}
