// * Lazy Propagation Segment Tree
// * range SET update
// * range ADD update
// * range SUM query
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define m (l+r)/2 // mid
#define lv 2*v // left vertex
#define rv 2*v+1 // right vertex

struct Node {
  ll val = 0, lz_add = 0, lz_set = 0;
};

int n, q;
vector<Node> tree;
vector<ll> a;

void push_down(int v, int l, int r){
  if(tree[v].lz_set != 0){ // range set
    tree[lv].lz_set = tree[rv].lz_set = tree[v].lz_set;
    tree[lv].val = (m-l+1) * tree[v].lz_set;
    tree[rv].val = (r-(m+1)+1) * tree[v].lz_set;
    tree[lv].lz_add = tree[rv].lz_add = 0;
    tree[v].lz_set = 0;
  }
  else if(tree[v].lz_add != 0){ // range add
    if(tree[lv].lz_set == 0)
      tree[lv].lz_add += tree[v].lz_add;
    else{
      tree[lv].lz_set += tree[v].lz_add;
      tree[lv].lz_add = 0;
    }

    if(tree[rv].lz_set == 0)
      tree[rv].lz_add += tree[v].lz_add;
    else{
      tree[rv].lz_set += tree[v].lz_add;
      tree[rv].lz_add = 0;
    }

    tree[lv].val += (m-l+1) * tree[v].lz_add;
    tree[rv].val += (r-(m+1)+1) * tree[v].lz_add;
    tree[v].lz_add = 0;
  }
}

void build(int v, int l, int r){
  if(l == r){
    tree[v].val = a[l];
    return;
  }

  build(lv, l, m);
  build(rv, m+1, r);
  tree[v].val = tree[lv].val + tree[rv].val;
}

void add(int v, int l, int r, int a, int b, ll x){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v].val += x * (r-l+1);
    if(tree[v].lz_set == 0)
      tree[v].lz_add += x;
    else
      tree[v].lz_set += x;
    return;
  }

  push_down(v, l, r);
  add(lv, l, m, a, b, x);
  add(rv, m+1, r, a, b, x);
  tree[v].val = tree[lv].val + tree[rv].val;
}

void _set(int v, int l, int r, int a, int b, ll x){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v].val = x * (r-l+1);
    tree[v].lz_set = x;
    tree[v].lz_add = 0;
    return;
  }

  push_down(v, l, r);
  _set(lv, l, m, a, b, x);
  _set(rv, m+1, r, a, b, x);
  tree[v].val = tree[lv].val + tree[rv].val;
}

ll sum(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v].val;
  
  push_down(v, l, r);
  return sum(lv, l, m, a, b) + sum(rv, m+1, r, a, b);
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
      add(1, 1, n, a, b, x);
    }
    else if(op == 2){
      cin >> x;
      _set(1, 1, n, a, b, x);
    }
    else if(op == 3)
      cout << sum(1, 1, n, a, b) << "\n";
  }
}