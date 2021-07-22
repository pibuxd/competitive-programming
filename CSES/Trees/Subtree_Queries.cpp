// * Euler Tour Technique using Segment Tree PURQ
// * Flattening a tree into an array to easily query and update subtrees.
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q, id;
vector<int> val, sub_size, ids, order;
vector<vector<int>> G;
vector<long long> tree;

void build(int v = 1, int l = 1, int r = n){
  if(l == r){
    tree[v] = val[order[l]];
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = tree[2*v] + tree[2*v+1];
}

void update(int v, int l, int r, int k, int x){
  if(l == r){
    tree[v] = val[order[l]];
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    update(2*v, l, m, k, x);
  else
    update(2*v+1, m+1, r, k, x);
  tree[v] = tree[2*v] + tree[2*v+1]; 
}

long long query(int v, int l, int r, int start, int end){
  if(l >= start && r <= end)
    return tree[v];
  if(l > end || r < start)
    return 0;
  
  int m = (l+r)/2;
  long long q1 = query(2*v, l, m, start, end);
  long long q2 = query(2*v+1, m+1, r, start, end);
  return q1 + q2;
}

void dfs(int v = 1, int p = 0){
  order[id] = v;
  ids[v] = id;
  id++;
  for(int x : G[v]){
    if(x == p) continue;
    dfs(x, v);
    sub_size[v] += sub_size[x];
  }
}

int main(){
  fastio;
  cin >> n >> q;

  val.resize(n+1);
  sub_size.resize(n+1, 1);
  G.resize(n+1);
  ids.resize(n+1);
  order.resize(n+1);
  tree.resize(4*(n+1));

  for(int i = 1; i <= n; i++)
    cin >> val[i];
  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  id = 1;
  dfs();
  
  // cout << "\nids:\t";
  // for(int i : ids)
  //   cout << i << " ";
  // cout << "\norder:\t";
  // for(int i : order)
  //   cout << i << " ";
  // cout << "\nsub:\t";
  // for(int i : order)
  //   cout << sub_size[i] << " ";
  // cout << "\nval:\t";
  // for(int i : order)
  //   cout << val[i] << " "; 
  // cout << "\n\n";

  build();
  while(q--){
    int operation;
    cin >> operation;
    if(operation == 1){
      int k, x;
      cin >> k >> x;
      val[order[ids[k]]] = x; // ok
      update(1, 1, n, ids[k], x);
    } else{
      int k;
      cin >> k;
      cout << query(1, 1, n, ids[k], ids[k] + sub_size[order[ids[k]]] - 1) << "\n";
    }
  }
} 