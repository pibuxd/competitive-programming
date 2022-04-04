// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Lazy Propagation Segment Tree
// * range ADD update
// * range MAX query
#include <bits/stdc++.h>
using namespace std;

#define m (l+r)/2 // mid
#define lv (2*v) // left vertex
#define rv (2*v+1) // right vertex

struct Node {
  int val = 0, lz = 0;
};

int n, q;
vector<int> a;
vector<Node> tree;

void push_down(int v){
  if(tree[v].lz == 0)
    return;
  tree[lv].val += tree[v].lz;
  tree[rv].val += tree[v].lz;
  tree[lv].lz += tree[v].lz;
  tree[rv].lz += tree[v].lz;
  tree[v].lz = 0;
}

void push_up(int v){
  tree[v].val = max(tree[lv].val, tree[rv].val);
}

void build(int v, int l, int r){
  if(l == r){
    tree[v].val = a[l];
    tree[v].lz = 0;
    return;
  }

  build(lv, l, m);
  build(rv, m+1, r);
  push_up(v);
}

void update(int v, int l, int r, int a, int b, int x){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v].val += x;
    tree[v].lz += x;
    return;
  }

  push_down(v);
  update(lv, l, m, a, b, x);
  update(rv, m+1, r, a, b, x);
  push_up(v);
}

int query(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v].val;

  push_down(v);
  return max(query(lv, l, m, a, b), query(rv, m+1, r, a, b));
}

int main(){
  cin >> n >> q;
  a.resize(n+1);
  tree.resize(4*(n+1));

  for(int i = 1; i <= n; i++) 
    cin >> a[i];
  build(1, 1, n);

  while(q--){
    int op, a, b, x;
    cin >> op >> a >> b;

    if(op == 1){
      cin >> x;
      update(1, 1, n, a, b, x);
    }
    else if(op == 2)
      cout << query(1, 1, n, a, b) << "\n";
  }
}