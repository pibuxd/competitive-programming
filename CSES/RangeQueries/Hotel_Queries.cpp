// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * MAX segmnet tree
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<int> a, tree;

void build(int v, int l, int r){
  if(l == r){
    tree[v] = a[l];
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = max(tree[2*v], tree[2*v+1]);
}

void query(int v, int l, int r, int val){
  if(l == r){
    tree[v] -= val;
    cout << l << " ";
    return;
  }
  int m = (l+r)/2;
  if(tree[2*v] >= val)
    query(2*v, l, m, val);
  else
    query(2*v+1, m+1, r, val);

  tree[v] = max(tree[2*v], tree[2*v+1]);
}

int main(){
  fastio;
  cin >> n >> q;
  a.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  tree.resize(4*(n+1));
  build(1, 1, n);

  while(q--){
    int i;
    cin >> i;
    if(tree[1] < i)
      cout << "0 ";
    else
      query(1, 1, n, i);
  }
}