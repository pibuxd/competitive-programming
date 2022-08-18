#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<vector<int>> G;
vector<int> kol; // 0 - N, 1 - K, 2 - S
vector<bool> vis;

void dfs(int v, int k){
  vis[v] = true;
  kol[v] = k;
  
  for(int x : G[v]){
    if(!vis[x])
      dfs(x, k == 1 ? 2 : 1);
  }
}

bool solve(){
  for(int i = 1; i <= n; i++)
    if(G[i].empty())
      return false;

  vis.assign(n+1, false);
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i, 1);
  
  return true;
}

int main(){
  fastio;
  cin >> n >> m;

  kol.assign(n+1, 0);
  G.assign(n+1, vector<int>());

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bool s = solve();

  if(!s){
    cout << "NIE\n";

  } else{
    cout << "TAK\n";
    for(int i = 1; i <= n; i++)
      cout << (kol[i] == 1 ? 'K' : 'S') << "\n";
  }
}