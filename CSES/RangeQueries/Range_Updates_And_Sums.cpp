// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Lazy Propagation Segment Tree
// * range SET update
// * range INCREASE update
// * range SUM query
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
  ll val = 0, lz_add = 0, lz_set = 0;
};

int n, q;
vector<Node> tree;
vector<ll> a;

void push_down(int v, int l, int r){
  int m = (l+r)/2;

  if(tree[v].lz_set != 0){ // range set
    tree[2*v].lz_set = tree[2*v+1].lz_set = tree[v].lz_set;
    tree[2*v].val = (m-l+1) * tree[v].lz_set;
    tree[2*v+1].val = (r-(m+1)+1) * tree[v].lz_set;
    tree[2*v].lz_add = tree[2*v+1].lz_add = 0;
    tree[v].lz_set = 0;
  }
  else if(tree[v].lz_add != 0){ // range add
    if(tree[2*v].lz_set == 0)
      tree[2*v].lz_add += tree[v].lz_add;
    else{
      tree[2*v].lz_set += tree[v].lz_add;
      tree[2*v].lz_add = 0;
    }

    if(tree[2*v+1].lz_set == 0)
      tree[2*v+1].lz_add += tree[v].lz_add;
    else{
      tree[2*v+1].lz_set += tree[v].lz_add;
      tree[2*v+1].lz_add = 0;
    }

    tree[2*v].val += (m-l+1) * tree[v].lz_add;
    tree[2*v+1].val += (r-(m+1)+1) * tree[v].lz_add;
    tree[v].lz_add = 0;
  }
}

void build(int v = 1, int l = 1, int r = n){
  if(l == r){
    tree[v].val = a[l];
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v].val = tree[2*v].val + tree[2*v+1].val;
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

  int m = (l+r)/2;
  push_down(v, l, r);
  add(2*v, l, m, a, b, x);
  add(2*v+1, m+1, r, a, b, x);
  tree[v].val = tree[2*v].val + tree[2*v+1].val;
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

  int m = (l+r)/2;
  push_down(v, l, r);
  _set(2*v, l, m, a, b, x);
  _set(2*v+1, m+1, r, a, b, x);
  tree[v].val = tree[2*v].val + tree[2*v+1].val;
}

ll sum(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v].val;
  
  int m = (l+r)/2;
  push_down(v, l, r);
  return sum(2*v, l, m, a, b) + sum(2*v+1, m+1, r, a, b);
}

int main(){
  cin >> n >> q;
  a.resize(n+1);
  tree.resize(4*(n+1));

  for(int i = 1; i <= n; i++) 
    cin >> a[i];
  build();

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