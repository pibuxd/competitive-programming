// * Segment Tree
// * POINT update, RANGE query
// * in this example I wrote a MINIMUM query
// * I commented on would it looks like for a SUM query
#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int n, m;
vector<int> tree, in;

void build(int v, int l, int r){
  if(l == r){
    tree[v] = in[l];
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = min(tree[2*v], tree[2*v+1]); // tree[v] = tree[2*v] + tree[2*v+1];
}

int query(int v, int l, int r, int start, int end){
  if(l >= start && r <= end)
    return tree[v];
  if(l > end || r < start)
    return INF; // return 0;
  
  int m = (l+r)/2;
  int q1 = query(2*v, l, m, start, end);
  int q2 = query(2*v+1, m+1, r, start, end);
  return min(q1, q2); // return q1 + q2;
}

void update(int v, int l, int r, int val, int i){
  if(l == r){
    tree[v] = val;
    return;
  }
  int m = (l+r)/2;
  if(m >= i)
    update(2*v, l, m, val, i);
  else
    update(2*v+1, m+1, r, val, i);
  tree[v] = min(tree[2*v], tree[2*v+1]); // tree[v] = tree[2*v] + tree[2*v+1];
}

int main(){
  cin >> n >> m;
  in.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> in[i];
  
  tree.resize(4*n+1);
  build(1, 1, n);

  while(m--){
    int operation, x, y;
    cin >> operation >> x >> y;
    if(operation == 1)
      update(1, 1, n, y, x);
    else
      cout << query(1, 1, n, x, y) << '\n';
  }
}