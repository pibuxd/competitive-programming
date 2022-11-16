#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lv (2*v)
#define rv (2*v+1)
#define m ((l+r)/2)

int n, q;
vector<vector<int>> tree;
vector<vector<int>> s;

void updtree(int v, int l, int r, int idx, int val, vector<int> &t){
  if(l == r){
    t[v] += val;
    return;
  }

  if(idx <= m) updtree(lv, l, m, idx, val, t);
  else updtree(rv, m+1, r, idx, val, t);
  t[v] = t[lv] + t[rv];
}

void upd(int v, int l, int r, int idxi, int idxj, int val){
  if(l == r){
    return updtree(1, 1, n, idxj, val, tree[v]);
  }
  if(idxi <= m) upd(lv, l, m, idxi, idxj, val);
  else upd(rv, m+1, r, idxi, idxj, val);
  updtree(1, 1, n, idxj, val, tree[v]);
}

void upd(int i, int j, int val){
  upd(1, 1, n, i, j, val);
}

int qrytree(int v, int l, int r, int a, int b, vector<int> &t){
  if(l > b || r < a) return 0;
  if(a <= l && r <= b) return t[v];
  return qrytree(lv, l, m, a, b, t) + qrytree(rv, m+1, r, a, b, t);
}

int qry(int v, int l, int r, int a, int b, int i, int j){
  if(l > b || r < a) return 0;
  if(a <= l && r <= b) return qrytree(1, 1, n, i, j, tree[v]);
  return qry(lv, l, m, a, b, i, j) + qry(rv, m+1, r, a, b, i, j);
}

int qry(int i1, int j1, int i2, int j2){
  return qry(1, 1, n, i1, i2, j1, j2);
}

int main(){
  fastio;
  cin >> n >> q;
  
  tree.resize(2*(1<<(int)ceil(log2(n)))+1, vector<int>(2*(1<<(int)ceil(log2(n)))+1));
  s.resize(n+1, vector<int>(n+1, -1));

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      char c; cin >> c;
      if(c == '*'){
        s[i][j] = 1;
        upd(i, j, 1);
      }
    }

  while(q--){
    int op; cin >> op;
    if(op == 1){
      int i, j; cin >> i >> j;
      s[i][j] *= -1;
      upd(i, j, s[i][j]);

    } else{
      int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
      cout << qry(i1, j1, i2, j2) << "\n";
    }
  }
}
