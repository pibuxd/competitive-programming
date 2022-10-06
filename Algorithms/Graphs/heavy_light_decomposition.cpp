// * HLD + Lazy Segment Tree with RANGE SET update and RANGE SUM query
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define lv (2*v)
#define rv (2*v+1)
#define m ((l+r)/2)

int n, q, nr;
vector<vector<int>> G;
vector<int> tree, lazy, sub, id, hpar, hch, parent;

void pushdown(int v, int l, int r){
  if(lazy[v] == -1)
    return;

  tree[lv] = (m-l+1) * lazy[v], 
  tree[rv] = (r-(m+1)+1) * lazy[v];

  lazy[lv] = lazy[rv] = lazy[v];
  lazy[v] = -1;
}

void upd(int v, int l, int r, int a, int b, int val){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v] = (r-l+1) * val;
    lazy[v] = val;
    return;
  }

  pushdown(v, l, r);
  upd(lv, l, m, a, b, val);
  upd(rv, m+1, r, a, b, val);
  tree[v] = tree[lv] + tree[rv];
}

int qry(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v];

  pushdown(v, l, r);
  return qry(lv, l, m, a, b) + qry(rv, m+1, r, a, b);
}

void upd(int val, int a, int b){
  if(a > b) swap(a, b);
  //cout << "UPD on: " << a << ", " << b << "\n";
  upd(1, 1, n, a, b, val);
}

int qry(int a, int b){
  if(a > b) swap(a, b);
  //cout << "QRY on: " << a << ", " << b << "\n";
  return qry(1, 1, n, a, b);
}

void dfssub(int v, int p){
  parent[v] = p;
  sub[v] = 1;

  for(int x : G[v])
    if(x != p){
      dfssub(x, v);
      sub[v] += sub[x];
    }
  for(int x : G[v])
    if(x != p && sub[x] >= sub[v]/2 + (sub[v]%2)){ // krawedz heavy znaleziona
      hch[v] = x, hpar[x] = v;
      break;
    }
}

void dfshld(int v, int p){
  id[v] = ++nr;
  if(hch[v]){ // bo najpierw ide do krawedzi heavy
    hpar[hch[v]] = hpar[v];
    dfshld(hch[v], v);
  }

  for(int x : G[v])
    if(x != p && x != hch[v]) // jesli nie parent i jesli nie heavy
      dfshld(x, v);
}

int par(int v){
  if(hpar[v] != v) return hpar[v];
  return parent[v];
}

int __par(int v){
  if(hpar[v] != v) return hch[hpar[v]];
  return v;
}

vector<vector<int>> getsegments(int a, int b){
  if(id[a] < id[b]) swap(a, b);

  vector<vector<int>> seg;
  if(a == b) return seg;
  
  while(id[par(a)] > id[b]){
    seg.push_back({id[a], id[__par(a)]});
    a = par(a);
  }
  
  if(parent[a] == b){
    seg.push_back({id[a], id[a]});
    return seg;
  }

  if(id[b] < id[parent[a]]){
    seg.push_back({id[a], id[hch[b]]});
    return seg;
  }
  
  seg.push_back({id[a], id[a]});
    
  while(id[par(b)] > id[parent[a]]){
    seg.push_back({id[b], id[__par(b)]});
    b = par(b);
  }
  
  if(parent[a] == parent[b]){
    seg.push_back({id[b], id[b]});
    return seg;
  }

  if(parent[a] != parent[b]){
    seg.push_back({id[b], id[hch[parent[a]]]});
    return seg;
  }
  return seg;
}

void updpath(int val, int a, int b){
  vector<vector<int>> seg = getsegments(a, b);
  for(vector<int> &s : seg)
    upd(val, s[1], s[0]);
}

int qrypath(int a, int b){
  if(a == b) return 0;

  int res = 0;
  vector<vector<int>> seg = getsegments(a, b);
  for(vector<int> &s : seg)
    res += qry(s[1], s[0]);

  return res;
}

int main(){
  fastio;
  cin >> n >> q;

  G.resize(n+1);
  sub.assign(n+1, 0); // wielkosc poddrzewa
  hpar.assign(n+1, 0); // heavy parent
  hch.assign(n+1, 0); // heavy child
  parent.assign(n+1, 0); // parent
  id.assign(n+1, 0); // preorder

  tree.assign(2*(1<<(int)ceil(log2(n)))+1, 0);
  lazy.assign(2*(1<<(int)ceil(log2(n)))+1, -1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfssub(1, 0);

  for(int i = 1; i <= n; i++)
    hpar[i] = i;

  nr = 0;
  dfshld(1, 0);

  while(q--){
    int op, a, b; cin >> op >> a >> b;
    if(op == 1) updpath(1, a, b);
    else if(op == 2) updpath(0, a, b);
    else if(op == 3) cout << qrypath(a, b) << "\n";
  }
}
