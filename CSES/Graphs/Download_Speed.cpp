// * Maximum flow - Ford-Fulkerson algorithm
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m, MX = 1e17;
vector<vector<int>> G;
map<array<int, 2>, int> M;
vector<bool> vis;

int dfs(int v, int currd){
  vis[v] = true;
  if(v == n)
    return currd;

  for(int x : G[v]){
    if(M[{v, x}] > 0 && !vis[x]){
      int d = dfs(x, min(currd, M[{v, x}]));
      M[{v, x}] -= d;
      M[{x, v}] += d;

      if(d == 0)
        continue;
      else
        return d;
    }
  }

  return 0;
}

signed main(){
  fastio;
  cin >> n >> m;

  G.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back(b);
    G[b].push_back(a);
    M[{a, b}] += c;
  }

  int maxflow = 0;
  while(true){
    vis.assign(n+1, false);
    int d = dfs(1, MX);
    maxflow += d;

    if(d == 0)
      break;
  }

  cout << maxflow;
}