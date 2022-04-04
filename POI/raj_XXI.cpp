// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * SCC + topological sort + segment tree
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define INF INT_MAX
int n, m;
vector<vector<int>> G, _G;
vector<pair<int, int>> edges;
vector<int> topo, _topo, topo_idx, dist_start, dist_end, dist_before, dist_after;
vector<bool> vis;

#define dist_with(a, b) dist_end[a] + 1 + dist_start[b]

struct lazy_segment_tree {
  #define lc 2*v
  #define rc 2*v+1
  #define mid (l+r)/2

  int n;
  vector<int> tree;

  lazy_segment_tree(int _n){
    n = _n;
    tree = vector<int>(4*(n+1), 0);
  }

  void update(int v, int l, int r, int a, int b, int x){
    if(l > b || r < a)
      return;
    if(a <= l && r <= b){
      tree[v] = max(tree[v], x);
      return;
    }

    update(lc, l, mid, a, b, x);
    update(rc, mid+1, r, a, b, x);
  }

  int query(int v, int l, int r, int idx){
    if(l == r)
      return tree[v];
    
    tree[lc] = max(tree[lc], tree[v]);
    tree[rc] = max(tree[rc], tree[v]);
    tree[v] = 0;

    if(idx <= mid)
      return query(lc, l, mid, idx);
    else
      return query(rc, mid+1, r, idx);
  }
  
  void update(int l, int r, int x){
    l++, r++;
    return update(1, 1, n, l, r, x);
  }

  int query(int idx){
    idx++;
    return query(1, 1, n, idx);
  }
};

void dfs(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs(x);
  
  _topo.push_back(v);
}

int main(){
  fastio;
  cin >> n >> m;
  G = _G = vector<vector<int>>(n+1, vector<int>());
  edges = vector<pair<int, int>>(m);
  topo_idx = dist_start = dist_end = dist_before = dist_after = vector<int>(n+1, 0);
  vis = vector<bool>(n+1, false);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    _G[b].push_back(a);
    edges[i] = {a, b};
  }

  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i);
  topo = _topo;
  reverse(topo.begin(), topo.end());
  for(int i = 0; i < n; i++)
    topo_idx[topo[i]] = i;
  // cout << "\n";
  // for(int t : topo)
  //   cout << t << " ";
  // cout << "\n";
  for(int v : _topo){
    for(int x : G[v])
      dist_start[v] = max(dist_start[v], dist_start[x]+1);
  }
  
  for(int v : topo){
    for(int x : _G[v])
      dist_end[v] = max(dist_end[v], dist_end[x]+1);
  }

  int last = 0;
  for(int v : _topo){
    dist_after[v] = max(dist_after[last], dist_start[last]);
    last = v;
  }

  last = 0;
  for(int v : topo){
    dist_before[v] = max(dist_before[last], dist_end[last]);
    last = v;
  }

  lazy_segment_tree sg(n);
  
  for(pair<int, int> &e : edges){
    int e1 = e.first, e2 = e.second;
    int l = dist_with(e1, e2);
    sg.update(topo_idx[e1]+1, topo_idx[e2]-1, l);
  }

  // cout << "\nBEYOND:\n";
  int mn = INF, idx;
  for(int i = 0; i < n; i++){
    int dist_beyond = sg.query(i);
    // cout << topo[i] << ": " << dist_beyond << "\n";
    int curr_max = max({dist_before[topo[i]], dist_beyond, dist_after[topo[i]]});
    if(mn > curr_max)
      mn = curr_max, idx = topo[i];
  }

  // cout << "\n\n";
  cout << idx << " " << mn << "\n";

  // cout << "\nDIST_START:\n";
  // for(int i = 1; i <= n; i++)
  //   cout << i << ": " << dist_start[i] << "\n";
  // cout << "\nDIST_END:\n";
  // for(int i = 1; i <= n; i++)
  //   cout << i << ": " << dist_end[i] << "\n";
  // cout << "\nDIST_BEFORE:\n";
  // for(int i = 1; i <= n; i++)
  //   cout << i << ": " << dist_before[i] << "\n";
  // cout << "\nDIST_AFTER:\n";
  // for(int i = 1; i <= n; i++)
  //   cout << i << ": " << dist_after[i] << "\n";
}