// * Segment Tree
// * POINT update, RANGE query
// * in this example I wrote a MINIMUM query
// * I commented it looks like for a SUM query
#include <bits/stdc++.h>
using namespace std;

#define m (l+r)/2 // mid
#define lv 2*v // left vertex
#define rv 2*v+1 // right vertex

const int INF = INT_MAX;
int n, q;
vector<int> tree, a;

void build(int v, int l, int r){
  if(l == r){
    tree[v] = a[l];
    return;
  }

  build(lv, l, m);
  build(rv, m+1, r);
  tree[v] = min(tree[lv], tree[rv]); // tree[v] = tree[lv] + tree[rv];
}

int query(int v, int l, int r, int start, int end){
  if(l >= start && r <= end)
    return tree[v];
  if(l > end || r < start)
    return INF; // return 0;
  

  int q1 = query(lv, l, m, start, end);
  int q2 = query(rv, m+1, r, start, end);
  return min(q1, q2); // return q1 + q2;
}

void update(int v, int l, int r, int val, int i){
  if(l == r){
    tree[v] = val;
    return;
  }

  if(m >= i)
    update(lv, l, m, val, i);
  else
    update(rv, m+1, r, val, i);
  tree[v] = min(tree[lv], tree[rv]); // tree[v] = tree[lv] + tree[rv];
}

int main(){
  cin >> n >> q;
  a.resize(n+1);
  tree.resize(4*n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  build(1, 1, n);

  while(q--){
    int operation, x, y;
    cin >> operation >> x >> y;
    if(operation == 1)
      update(1, 1, n, y, x);
    else
      cout << query(1, 1, n, x, y) << '\n';
  }
}