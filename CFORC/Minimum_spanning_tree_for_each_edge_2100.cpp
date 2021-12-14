// a - vertex 1, b - vertex 2, w - weight of edge(a, b)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Edge{
  int a, b, w, nr;
  bool operator<(const Edge &other){
    return w < other.w; 
  }
};

struct Vertex{
  int v, w;
};

int n, m, root, LOGN;
long long mst_weight;
vector<Edge> edges;
vector<bool> in_mst;
vector<vector<Vertex>> G;
vector<int> parent, depth, it, weight;
vector<vector<int>> up;

void make_set(int v){
  parent[v] = v;
}

int find_set(int v){
  if(v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b)
    parent[b] = a;
}

void init_mst(){
  mst_weight = 0;
  sort(edges.begin(), edges.end());
  /*
  for(auto e : edges){
    cout << e.a << " " << e.b << ": " << e.w  << " / " << e.nr  << "\n";
  }
  */

  for(int i = 1; i <= n; i++)
    make_set(i);

  for(int i = 0; i < m; i++){
    it[edges[i].nr] = i;
    int a_union = find_set(edges[i].a);
    int b_union = find_set(edges[i].b);

    if(a_union != b_union){
      union_sets(a_union, b_union);
      mst_weight += edges[i].w;
      in_mst[edges[i].nr] = true;
      G[edges[i].a].push_back({edges[i].b, edges[i].w});
      G[edges[i].b].push_back({edges[i].a, edges[i].w});
    }
  }
}

void dfs(int v, int p){
  for(Vertex x : G[v]){
    if(x.v == p) continue;
    up[x.v][0] = v;
    weight[x.v] = x.w;
    depth[x.v] = depth[v] + 1;

    for(int i = 1; i < LOGN; i++)
      up[x.v][i] = up[up[x.v][i-1]][i-1];
    
    dfs(x.v, v);
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

  for(int i = LOGN - 1; i >= 0; i--)
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  
  return up[a][0];
}

int max_on_path(int a, int b){
  int l = lca(a, b);
  //cout <<  l << " ";
  int maxe = 0;
  while(a != l){
    int par = up[a][0];
    //cout << weight[a] << "\' ";
    maxe = max(maxe, weight[a]);
    a = par;
  }

  while(b != l){
    int par = up[b][0];
    //cout << "b:" << b << ")" << "par:" << par  << "] " << weight[b] << "\' ";
    maxe = max(maxe, weight[b]);
    b = par;
  }
  //cout << "MAXE: " << maxe << "\n";
  return maxe;
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  parent.resize(n+1);
  depth.resize(n+1);
  weight.resize(n+1);
  edges.resize(m);
  in_mst.resize(m);
  it.resize(m);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    edges[i] = {a, b, w, i};
  }

  init_mst();

  for(int i = 0; i < m; i++)
    if(in_mst[i]){
      root = edges[it[i]].a;
      break;
    }
  
  LOGN = ceil(log2(n)) + 1;
  up.resize(n+1, vector<int>(LOGN));
  dfs(root, 0);
  
  /*
  for(int i = 0; i < m; i++){
    cout << edges[it[i]].a << " " << edges[it[i]].b << ": " << edges[it[i]].w << "\n";
  } cout << "\n";
  */

  for(int i = 0; i < m; i++){
    if(in_mst[i])
      cout << mst_weight << "\n";
    else
      cout << mst_weight + edges[it[i]].w - max_on_path(edges[it[i]].a, edges[it[i]].b) << "\n";
  }

  /*
  cout << "\n\n";
  for(int i = 1; i <= n; i++){
    cout << i << "\n";
    for(auto x : G[i]){
      cout << "\t" << x.v << ": " << x.w << "\n";
    }
  }
  */
}