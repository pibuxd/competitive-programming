#include <bits/stdc++.h>
using namespace std;

/**
 * lazy propagation segment tree
 * * range add, range sum, range set
 */

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXM = 6e4+1; 
int n, q;
vector<int> tree, lazy;

void push(int v){
  tree[2*v] += lazy[v];
  lazy[2*v] += lazy[v];
  tree[2*v+1] += lazy[v];
  lazy[2*v+1] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int l, int r, int x, int y, int val){
  if(x > y){
    return;
  }
  if(x == l && y == r){
    tree[v] += val;
    lazy[v] += val;
  } else{
    push(v);
    int mid = (l + r) / 2;
    update(v*2, l, mid, x, min(x, mid), val);
    update(v*2+1, mid+1, r, max(y, mid+1), y, val);
    tree[v] = min(tree[2*v], tree[2*v+1]);
  }
}

int query(int v, int l, int r, int x, int y){
  if(x > y){
    return MAXM;
  }
  if(x <= l && y >= r){
    return tree[v];
  }

  push(v);
  int mid = (r + l) / 2;
  return(min(query(2*v, l, mid, x, min(y, mid)), query(2*v+1, mid+1, r, max(x, mid+1), y)));
}

int main(){
  fastio;
  cin >> n >> q;
  tree = lazy = vector<int>(2*n+1);
  

  while(q--){
    int operation, a, b, val;
    cin >> operation;

    if(operation == 1){
      cin >> a >> b >> val;
      update(1, 1, n, a, b, val)
    }

    cin >> a >> b >> val;
    
  }
}