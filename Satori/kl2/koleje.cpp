/**
 * lazy propagation segment tree
 * * range subtract, range minimum
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
int n, m, q;
vector<int> tree, lazy;
 
void push(int v){
  tree[2*v] += lazy[v];
  lazy[2*v] += lazy[v];
  tree[2*v+1] += lazy[v];
  lazy[2*v+1] += lazy[v];
  lazy[v] = 0;
}
 
void update(int v, int tl, int tr, int l, int r, int addend){
  if(l > r){
    return;
  }
  if(l == tl && r == tr){
    tree[v] += addend;
    lazy[v] += addend;
  } else{
    push(v);

    int tm = (tl + tr) / 2;
    update(v*2, tl, tm, l, min(r, tm), addend);
    update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
    tree[v] = min(tree[2*v], tree[2*v+1]);
  }
}
 
int query(int v, int tl, int tr, int l, int r){
  if(l > r){
    return INT_MAX;
  }
  if(l <= tl && tr <= r){
    return tree[v];
  }
 
  push(v);
  int tm = (tr + tl) / 2;
  return min(query(v*2, tl, tm, l, min(r, tm)), 
            query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
 
int main(){
  fastio;
  int t;
  cin >> t;
 
  while(t--){
    cin >> n >> m >> q;
    tree = lazy = vector<int>(10*n+1);
    update(1, 1, n, 1, n, m);
 
    while(q--){
      int tempa, tempb, val;
      cin >> tempa >> tempb >> val;

      tempb--; // ?
      int a = min(tempa, tempb);
      int b = max(tempa, tempb);
      int minimum = query(1, 1, n, a, b);
      // cout << minimum << ' '; debug

      if(val <= minimum){
        cout << "T\n";
        update(1, 1, n, a, b, -val);
      } else{
        cout << "N\n";
      }
    }
  }
}
