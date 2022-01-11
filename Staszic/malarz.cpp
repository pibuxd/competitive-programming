#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define m (l+r)/2 // mid
#define lv 2*v // left vertex
#define rv 2*v+1 // right vertex

struct Node {
  int val = 0;
  bool lz = false;
};

int n, q;
vector<Node> tree;

void push_down(int v, int l, int r){
  if(!tree[v].lz) return;

  tree[lv].val = (m-l+1) - tree[lv].val;
  tree[rv].val = (r-(m+1)+1) - tree[rv].val;
  tree[lv].lz = !tree[lv].lz;
  tree[rv].lz = !tree[rv].lz;
  tree[v].lz = false;
}

void push_up(int v){
  tree[v].val = tree[lv].val + tree[rv].val;
}

void build(int v, int l, int r){
  if(l == r){
    tree[v].val = 1;
    tree[v].lz = false;
    return;
  }

  build(lv, l, m);
  build(rv, m+1, r);
  push_up(v);
}

void update(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v].val = (r-l+1) - tree[v].val;
    tree[v].lz = !tree[v].lz;
    return;
  }

  push_down(v, l, r);
  update(lv, l, m, a, b);
  update(rv, m+1, r, a, b);
  push_up(v);
}

int query(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v].val;

    push_down(v, l, r);
  return query(lv, l, m, a, b) + query(rv, m+1, r, a, b);
}

int main(){
  fastio;
  cin >> n >> q;
  tree.resize(4*(n+1));

  build(1, 1, n);

  while(q--){
    char op;
    int a, b;
    cin >> op >> a >> b;

    if(op == '?'){
      cout << query(1, 1, n, a, b) << "\n";
    }
    else{
      update(1, 1, n, a, b);
    }
  }
}