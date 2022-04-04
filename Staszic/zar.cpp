// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<int>> G;
vector<int> dp1, dp2;

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;

    dfs(x, v);
  }

  auto val = [v, p]()->array<int, 2>{

    int t = 0, same = 0;

    for(int x : G[v]){
      if(x == p) continue;

      t += dp2[x];
      same += (dp1[x] == dp2[x]);
    }

    return {t + (same < 2), t + (same < 1)};
  }();

  dp1[v] = val[0];
  dp2[v] = val[1];
}

int main(){
  fastio;
  cin >> n;

  G.resize(n+1);
  dp1.resize(n+1, 0); // dp[i] koszt spalenia i-tego poddrzewa jesli nie pomoze parent
  dp2.resize(n+1, 0); // dp[i] koszt spalenia i-tego poddrzewa jesli pomoze parent

  for(int i = 1; i <= n-1; i++){ // wczytaj drzewo
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0); // wierzchołek 1 jest korzeniem

  cout << dp1[1];
}