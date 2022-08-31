#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, k, stsize, logn; // k-bak, stsize-l stacji
vector<vector<int>> G, up;
vector<int> stations, depth, upar, usiz; // upar - union parent, usiz - union size

void dfs(int v, int p){ // tylko po to zeby miec lca i tablice depth (obliczanie odleglosci)
  depth[v] = depth[p] + 1;
  up[v][0] = p;
  for(int i = 1; i <= logn; i++)
    up[v][i] = up[up[v][i-1]][i-1];
  for(int x : G[v])
    if(x != p)
      dfs(x, v);
}

int jump(int v, int j){ // binary lift
  for(int i = 0; i <= logn; i++)
    if(j & (1 << i))
      v = up[v][i];
  return v;
}

int lca(int a, int b){
  if(depth[a] < depth[b])
    swap(a, b);
  int c = depth[a] - depth[b];
  for(int i = 0; i <= logn; i++)
    if(c & (1 << i))
      a = up[a][i];
  if(a == b)
    return a;
  for(int i = logn; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];
  return up[a][0];
}

int union_find(int v){
  if(upar[v] == v) return v;
  return upar[v] = union_find(upar[v]);
}

void union_make(int a, int b){ // union find z optymalizacja small to large merge
  a = union_find(a), b = union_find(b);
  if(a != b){
    if(usiz[a] < usiz[b])
      swap(a, b);
    upar[b] = a;
    usiz[a] += usiz[b];
  }
}

void bfs(){ // bfs tylko po to aby zrobic unie stacji, czyli --
  // kazda stacja bierze do unii wierzcholki ktore ma w odleglosci k od siebie
  // pamietajmy ze pomiedzy kazda krawedzia jest wirtualny wierzcholek 
  for(int i = 1; i <= 2*n; i++)
    upar[i] = i, usiz[i] = 1;
  
  queue<pair<int, int>> Q; // [vertex, usedk]
  for(int s : stations) 
    Q.push({s, 0});
  vector<bool> vis(2*n+1);

  while(!Q.empty()){
    auto [v, usedk] = Q.front();
    Q.pop();

    if(usedk == k)
      continue;

    for(int x : G[v]){
      union_make(x, v);
      if(!vis[x]){
        vis[x] = true;
        Q.push({x, usedk+1});
      }
    }
  }
}

string ans(int a, int b){
  int l = lca(a, b);
  if(depth[a] + depth[b] - 2*depth[l] <= 2*k)
    return "TAK";

  // najpierw zuzywam polowe baku wierzcholka a
  // potem zuzywam polowe baku wierzcholka b
  int _k = k, _k2 = k;
  int _a = a;
  a = jump(a, min(_k, depth[a]-depth[l]));
  _k -= min(_k, depth[_a]-depth[l]);

  if(_k > 0)
    a = jump(b, depth[b]-depth[l]-_k);

  l = lca(a, b);
  int _b = b;
  b = jump(b, min(_k2, depth[b]-depth[l]));
  _k2 -= min(_k2, depth[_b]-depth[l]);
  if(_k2 > 0)
    b = jump(a, depth[a]-depth[l]-_k2);

  // sprawdzam czy po zuzyciu polowy baku wierzch a oraz b,
  // sa w tej samej unii
  if(union_find(a) == union_find(b))
    return "TAK";
  else
    return "NIE";
}

int main(){
  fastio;
  cin >> n >> k >> stsize;
  logn = 19;
  // size podwojny bo wirtualne wierzcholki
  G.resize(2*n+1);
  depth.resize(2*n+1);
  up.resize(2*n+1, vector<int>(logn+1));
  upar.resize(2*n+1);
  usiz.resize(2*n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(n+i);
    G[b].push_back(n+i);
    // daje wirtualny wierzcholek na srodku kazdej krawedzi
    G[n+i].push_back(a);
    G[n+i].push_back(b);
  }

  for(int i = 1; i <= stsize; i++){
    int st; cin >> st;
    stations.push_back(st);
  }
  
  dfs(1, 0);
  bfs();

  int q; cin >> q;
  while(q--){
    int a, b; cin >> a >> b;
    cout << ans(a, b) << "\n";
  }
}
