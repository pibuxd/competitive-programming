#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long
#define m ((l+r)/2)
#define lv (2*v)
#define rv (2*v+1)

int n, k, q, INF = 1e10;
vector<int> tree, lazy, tab;
vector<int> fen;

void add(int idx){
  for(; idx <= n; idx += idx & -idx)
    fen[idx]++;
}

int sum(int idx){
  int res = 0;
  for(; idx >= 1; idx -= idx & -idx)
    res += fen[idx];
  return res;
}

int sum(int a, int b){
  return sum(b) - sum(a-1);
}

void build(int v, int l, int r){
  if(l == r){
    tree[v] = tab[l];
    lazy[v] = 0;
    return;
  }
  
  build(lv, l, m);
  build(rv, m+1, r);
  tree[v] = max(tree[lv], tree[rv]);
}

void pushdown(int v){
  if(lazy[v] == 0) return;
  tree[lv] += lazy[v];
  tree[rv] += lazy[v];
  lazy[lv] += lazy[v];
  lazy[rv] += lazy[v];
  lazy[v] = 0;
}

void update(int v, int l, int r, int a, int b){
  if(l > b || r < a) return;
  if(a <= l && r <= b){
    tree[v]++;
    lazy[v]++;
    return;
  }
  pushdown(v);
  update(lv, l, m, a, b);
  update(rv, m+1, r, a, b);
  tree[v] = max(tree[lv], tree[rv]);
}

void walker(int v, int l, int r){
  if(l == r){
    add(l);
    tree[v] = -INF;
    return; 
  }
  pushdown(v);

  if(tree[lv] >= k)
    walker(lv, l, m);
  if(tree[rv] >= k)
    walker(rv, m+1, r);
  tree[v] = max(tree[lv], tree[rv]);
}

void check(){
  if(tree[1] < k) return;
  walker(1, 1, n);
}

signed main(){
  fastio;
  cin >> n >> k >> q;

  tree.resize(2*(1<<(int)ceil(log2(n)))+1, 0);
  lazy.resize(2*(1<<(int)ceil(log2(n)))+1, 0);
  tab.resize(n+1, 0);
  fen.resize(n+1, 0);
  
  for(int i = 1; i <= n; i++){
    cin >> tab[i];
    if(tab[i] >= k){
      tab[i] = -INF;
      add(i);
    }
  }

  build(1, 1, n);
  int res = 0;

  while(q--){
    int op; cin >> op;

    if(op == 0){
      int a, b; cin >> a >> b;
      a++, b++;
      update(1, 1, n, a, b);

    } else{
      int p, q, r, s; cin >> p >> q >> r >> s;
      p++, q++, r++, s++;
      check();
      if(res % 2 == 0)
        res = sum(p, q);
      else
        res = sum(r, s);
      cout << res << "\n";
    }
  }
}
