// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int LOGN;
vector<int> depth;
vector<vector<int>> G, up;

void dfs(int v, int p){
  for(int x : G[v]){
    if(x == p) continue;

    depth[x] = depth[v] + 1;
    up[x][0] = v;

    for(int i = 1; i < LOGN; i++)
      up[x][i] = up[up[x][i-1]][i-1];
    
    dfs(x, v);
  }
}

int lca(int a, int b){
  if(depth[a] < depth[b])
    swap(a, b);
  int k = depth[a] - depth[b];

  for(int i = 0; i < LOGN; i++)
    if((k >> i) & 1)
      a = up[a][i];

  if(a == b)
    return a;

  for(int i = LOGN-1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}

int main(){
  fastio;
  int n, m;
  cin >> n >> m;

  LOGN = ceil(log2(n)) + 1;
  depth.resize(n+1);
  G.resize(n+1);
  up.resize(n+1, vector<int>(LOGN));

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    int x = lca(a, b);
    int dist = depth[a] - depth[x] + depth[b] - depth[x];
    cout << dist << "\n";
  }
}