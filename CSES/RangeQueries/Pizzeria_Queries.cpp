// * custom operation segmnet tree
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int INF = INT_MAX;
int n, q;
vector<int> a;
vector<array<int, 2>> l_tree, r_tree;

void l_build(int v, int l, int r){
  if(l == r){
    l_tree[v] = {a[l], l};
    return;
  }
  int m = (l+r)/2;
  l_build(2*v, l, m);
  l_build(2*v+1, m+1, r);

  if((l_tree[2*v][0] + abs(l_tree[2*v][1]-l)) <= (l_tree[2*v+1][0] + abs(l_tree[2*v+1][1]-l)))
    l_tree[v] = l_tree[2*v];
  else
    l_tree[v] = l_tree[2*v+1];
}

void r_build(int v, int l, int r){
  if(l == r){
    r_tree[v] = {a[l], l};
    return;
  }
  int m = (l+r)/2;
  r_build(2*v, l, m);
  r_build(2*v+1, m+1, r);

  if((r_tree[2*v][0] + abs(r_tree[2*v][1]-r)) <= (r_tree[2*v+1][0] + abs(r_tree[2*v+1][1]-r)))
    r_tree[v] = r_tree[2*v];
  else
    r_tree[v] = r_tree[2*v+1];
}

void build(){
  l_tree.resize(4*(n+1));
  r_tree.resize(4*(n+1));
  l_build(1, 1, n);
  r_build(1, 1, n);
}

void l_update(int v, int l, int r, int k, int val){
  if(l == r){
    l_tree[v] = {val, k};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    l_update(2*v, l, m, k, val);
  else
    l_update(2*v+1, m+1, r, k, val);

  if((l_tree[2*v][0] + abs(l_tree[2*v][1]-l)) <= (l_tree[2*v+1][0] + abs(l_tree[2*v+1][1]-l)))
    l_tree[v] = l_tree[2*v];
  else
    l_tree[v] = l_tree[2*v+1];
}

void r_update(int v, int l, int r, int k, int val){
  if(l == r){
    r_tree[v] = {val, k};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    r_update(2*v, l, m, k, val);
  else
    r_update(2*v+1, m+1, r, k, val);

  if((r_tree[2*v][0] + abs(r_tree[2*v][1]-r)) <= (r_tree[2*v+1][0] + abs(r_tree[2*v+1][1]-r)))
    r_tree[v] = r_tree[2*v];
  else
    r_tree[v] = r_tree[2*v+1];
}

void update(int k, int x){
  a[k] = x;
  l_update(1, 1, n, k, x);
  r_update(1, 1, n, k, x);
}

int l_query(int v, int l, int r, int start, int end, int k){
  if(l >= start && r <= end)
    return l_tree[v][0] + abs(l_tree[v][1] - k);
  if((l > end || r < start))
    return INF;

  int m = (l+r)/2;
  int q1 = l_query(2*v, l, m, start, end, k);
  int q2 = l_query(2*v+1, m+1, r, start, end, k);
  return min(q1, q2);
}

int r_query(int v, int l, int r, int start, int end, int k){
  if(l >= start && r <= end)
    return r_tree[v][0] + abs(r_tree[v][1] - k);
  if((l > end || r < start))
    return INT_MAX;

  int m = (l+r)/2;
  int q1 = r_query(2*v, l, m, start, end, k);
  int q2 = r_query(2*v+1, m+1, r, start, end, k);
  return min(q1, q2);
}

int query(int k){
  int lq = l_query(1, 1, n, k, n, k);
  int rq = r_query(1, 1, n, 1, k, k);
  return min(lq, rq);
}

int main(){
  fastio;
  cin >> n >> q;
  a.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  build();

  while(q--){
    int op;
    cin >> op;
    if(op == 1){
      int k, x;
      cin >> k >> x;
      update(k, x);
    } else{
      int k;
      cin >> k;
      cout << query(k) << '\n';
    }
  }
}