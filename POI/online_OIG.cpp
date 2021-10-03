// * Segment tree PURQ
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Node{
  int min, max, len, lmin, lmax, llen, lm, rmin, rmax, rlen, rm;
};

Node operator + (const Node &a, const Node &b){
  if(a.rm && b.lm){
    if(a.max < b.min)
      return {a.min, b.max, a.len+b.len, a.lmin, a.lmax, a.llen, a.lm, b.rmin, b.rmax, b.rlen, b.rm};
    else{
      if(a.len > b.len)
        return {a.min, a.max, a.len, a.lmin, a.lmax, a.llen, a.lm, }
    }
  } else if(a.rm && !b.lm){

  } else if(!a.rm && b.lm){
    
  } else if(!a.rm && !b.lm){
    
  }
}

int n;
vector<int> a;
vector<Node> tree;

void build(int v = 1, int l = 1, int r = n){
  if(l == r){
    tree[v] = {a[l], a[l], 1, a[l], a[l], 1, a[l], a[l], 1};
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = tree[2*v] + tree[2*v+1];
}

void update(int v, int l, int r, int k, int x){
  if(l == r){
    a[l] = x;
    tree[v] = {a[l], a[l], 1, a[l], a[l], 1, 1, a[l], a[l], 1, 1};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    update(2*v, l, m, k, x);
  else
    update(2*v+1, m+1, r, k, x);

  tree[v] = tree[2*v] + tree[2*v+1];
}

int query(){
  return tree[1].len;
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  tree.resize(4*(n+1));
  build();
  cout << query() << "\n";

  int q;
  cin >> q;
  while(q--){
    int k, x;
    cin >> k >> x;
    update(1, 1, n, k, x);
    cout << query() << "\n";
  }
}