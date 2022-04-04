// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, ans;
vector<vector<int> > G;
vector<pair<int, int> > dp;
vector<int> par;

void dfs(int v, int p){
  par[v] = p;
  int mx1 = 0, mx2 = 0;
  bool _s = false;

  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
    
    int add = (int)G[x].size() - 2;
    mx2 = max(mx2, dp[x].first + add);
    if(mx1 < mx2)
      swap(mx1, mx2);
    
    if(G[x].size() > 1) _s = true;
  }

  dp[v] = {mx1, mx2};
  int sum = mx1+mx2;
  if(!_s) sum--;
  ans = max(ans, sum + (int)G[v].size() - 2);
}

int main(){
  fastio;
  cin >> n;
  if(n == 2){
    cout << "0";
    return 0;
  }
  if(n == 3){
    cout << "1";
    return 0;
  }
  G.resize(n+1, vector<int>());
  dp.resize(n+1, {0, 0});
  par.resize(n+1, 0);

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  ans = 0;
  dfs(1, 0);
  cout << ans+2;
}