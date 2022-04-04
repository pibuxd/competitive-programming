// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int N, S, LOGN;
long long dlg;
bool waspath;
vector<vector<array<int, 2>>> G;
vector<int> depth;
vector<long long> dist;
vector<vector<int>> up;

void init(int n, int s){
  N = n, S = s;
  waspath = false;

  G.resize(N+1);
  dist.resize(N+1);
  LOGN = ceil(log2(N));

  if(S == 2 || S == 3){
    depth = vector<int>(N+1);
    up = vector<vector<int>>(N+1, vector<int>(LOGN+1));
  }
}

void dfsb(int v, int p, long long dis, int dest){
  if(v == dest){
    dlg = dis;
    return;
  }
  for(auto X : G[v]){
    int x = X[0];
    long long w = X[1];
    if(x == p) continue;
    dfsb(x, v, dis+w, dest);
  }
}

void build(int x, int y, int t){
  if(S == 1){
    dist[y] = dist[x] + t;
  }
  if(S == 3){
    dist[y] = dist[x] + t;
    depth[y] = depth[x] + 1;
    up[y][0] = x;

    for(int i = 1; i <= LOGN; i++)
      up[y][i] = up[up[y][i-1]][i-1];
  }

  G[x].push_back({y, t});
  G[y].push_back({x, t});
}

void dfs(int v, int p){
  up[v][0] = p;

  for(auto X : G[v]){
    int x = X[0];
    long long w = X[1];
    if(x == p) continue;

    dist[x] = dist[v] + w;
    depth[x] = depth[v] + 1;

    for(int i = 1; i <= LOGN; i++)
      up[x][i] = up[up[x][i-1]][i-1];

    dfs(x, v);
  }
}

int lca(int a, int b){
  if(depth[a] < depth[b])
    swap(a, b);
  int k = depth[a] - depth[b];

  for(int i = 0; i <= LOGN; i++)
    if((k >> i) & 1)
      a = up[a][i];

  if(a == b)
    return a;

  for(int i = LOGN; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];

  return up[a][0];
}

int path(int x, int y){
  if(S == 1){
    if(dist[x] > dist[y])
      swap(x, y);
    return dist[y] - dist[x];
  }
  if(S == 2){
    if(waspath == false){
      dfs(1, 0);
      waspath = true;
    }
    
    cout << lca(x, y) << " ";
    return dist[x] + dist[y] - 2*dist[lca(x, y)];
  }
  if(S == 3){
    cout << lca(x, y) << " ";
    return dist[x] + dist[y] - 2*dist[lca(x, y)];
  }
}