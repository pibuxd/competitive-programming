/**
 * * LCA - eulerian path method with segment tree
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  vector<vector<int>> G;
  vector<int> it;
  vector<pair<int, int>> eulerian_path, tree;
  int n, e_size = 0;

  Graph(int _n){
    n = _n;
    G.resize(n);
    tree.resize(10000001);
  }

  void push(int a, int b){
    G[b].push_back(a);
  }

  void mark(int v, int node_depth){
    eulerian_path.push_back({v, node_depth});
    e_size++;
    //depths[v] = node_depth;

    it[v] = e_size-1;
  }

  void dfs(int v, int node_depth = 0){
    mark(v, node_depth);

    for(int x : G[v]){
      dfs(x, node_depth + 1);
      mark(v, node_depth);
    }
  }

  void buildtree(int v, int l, int r){
    if(l == r){
      tree[v] = eulerian_path[l];
      return;
    } 

    int mid = (l + r) / 2;
    buildtree(2*v, l, mid);
    buildtree(2*v+1, mid+1, r);

    if(tree[2*v].second < tree[2*v+1].second){
      tree[v] = tree[2*v];
    } else{
      tree[v] = tree[2*v+1];
    }
  }

  void prepare(){
    it.resize(n, -1);

    dfs(0);

    buildtree(1, 0, eulerian_path.size()-1);
  }

  pair<int, int> query(int v, int l, int r, int x, int y){
    if(x > r || l > y){
      return {INT_MAX, INT_MAX};
    }
    if(x <= l && y >= r){
      return tree[v];
    }

    pair<int, int> q1, q2;
    int mid = (l + r) / 2;
    q1 = query(2*v, l, mid, x, y);
    q2 = query(2*v+1, mid+1, r, x, y);

    if(q1.second < q2.second){
      return q1;
    } else{
      return q2;
    }
  }

  int lca(int a, int b){
    int xx = min(it[a], it[b]), yy = max(it[a], it[b]);
    //cout << xx << ','<< yy << ' ';

    pair<int, int> minimum = query(1, 0, eulerian_path.size()-1, xx, yy);

    return minimum.first;
  }
};

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    Graph graph(n);

    for(int i = 1, v; i < n; i++){
      cin >> v;
      graph.push(i, v);
    }

    graph.prepare();

    int m;
    cin >> m;

    for(int a, b; m--;){
      cin >> a >> b;
      cout << graph.lca(a, b) << '\n';
    }

    cout << '\n';

    /*for(auto x : graph.eulerian_path){
      cout << x.first << ' ';
    } cout << '\n';

    for(auto x : graph.eulerian_path){
      cout << x.second << ' ';
    } cout << '\n';

    for(int x : graph.it){
      cout << x << ' ';
    } cout << '\n' << '\n';

    for(auto x : graph.tree){
      cout << x.first << ',' << x.second << ' ';
    }*/
  }
}