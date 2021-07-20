// doesn't work
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

struct Node{
  int l, r, s;
};

int n, q;
vector<Node> tree;
vector<int> a;

Node add(Node a, Node b){
  if(a.r + b.l + b.s + a.s >= a.s && a.r + b.l + b.s + a.s >= b.s)
    return {a.l, b.r, a.s + a.r + b.l + b.s};
  if(a.s > b.s)
    return {a.l, a.r+b.l+b.s+b.r, a.s};
  else
    return {a.l+a.s+a.r+b.l, b.r, b.s};
}

void build(int v, int l, int r){
  if(l == r){
    tree[v] = {0, 0, a[l]};
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  
  tree[v] = add(tree[2*v], tree[2*v+1]);
}

void update(int v, int l, int r, int k, int val){
  if(l == r){
    tree[v] = {0, 0, val};
    return;
  }

  int m = (l+r)/2;
  if(k <= m)
    update(2*v, l, m, k, val);
  else
    update(2*v+1, m+1, r, k, val);
  
  tree[v] = add(tree[2*v], tree[2*v+1]);
}

int query(){
  if(tree[1].s > 0)
    return tree[1].s;
  return 0;
}

int main(){
  fastio;
  cin >> n >> q;
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  tree.resize(4*n+1);
  build(1, 1, n);

  while(q--){
    int k, x;
    cin >> k >> x;
    update(1, 1, n, k, x);
    cout << query() << "\n";
  }
}