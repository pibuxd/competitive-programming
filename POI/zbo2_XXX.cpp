// * HLD + Lazy Segment Tree with RANGE SET update and RANGE SUM query
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

#define lv (2*v)
#define rv (2*v+1)
#define m ((l+r)/2)

int n, q, nr;
vector<vector<array<int, 2>>> G;
vector<int> lazy, sub, id, hpar, hch, parent, parc, idod, pref, dist;
vector<ll> tree;

int sum(int l, int r){
  return pref[r] - pref[l-1];
}

void prefbuild(){
  pref.assign(n+1, 0);
  for(int i = 1; i <= n; i++)
    pref[i] = pref[i-1] + parc[idod[i]];
}

void pushdown(int v, int l, int r){
  if(lazy[v] == 0)
    return;

  tree[lv] += (ll)lazy[v] * (ll)sum(l, m), 
  tree[rv] += (ll)lazy[v] * (ll)sum(m+1, r);

  lazy[lv] += lazy[v], lazy[rv] += lazy[v];
  lazy[v] = 0;
}

void upd(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v] += (ll)sum(l, r);
    lazy[v]++;
    return;
  }

  pushdown(v, l, r);
  upd(lv, l, m, a, b);
  upd(rv, m+1, r, a, b);
  tree[v] = tree[lv] + tree[rv];
}

ll qry(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return (ll)0;
  if(a <= l && r <= b)
    return tree[v];

  pushdown(v, l, r);
  return qry(lv, l, m, a, b) + qry(rv, m+1, r, a, b);
}

void upd(int a, int b){
  if(a > b) swap(a, b);
  upd(1, 1, n, a, b);
}

ll qry(int a, int b){
  if(a > b) swap(a, b);
  return qry(1, 1, n, a, b);
}

void dfssub(int v, int p){
  sub[v] = 1;

  for(auto [x, c] : G[v])
    if(x != p){
      parent[x] = v;
      parc[x] = c;
      dist[x] = dist[v] + c;

      dfssub(x, v);
      sub[v] += sub[x];
    }
  for(auto [x, c] : G[v])
    if(x != p && sub[x] >= sub[v]/2 + (sub[v]%2)){ // krawedz heavy znaleziona
      hch[v] = x, hpar[x] = v;
      break;
    }
}

void dfshld(int v, int p){
  id[v] = ++nr;
  idod[id[v]] = v;

  if(hch[v]){ // bo najpierw ide do krawedzi heavy
    hpar[hch[v]] = hpar[v];
    dfshld(hch[v], v);
  }

  for(auto [x, c] : G[v])
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

void updpath(int a, int b){
  vector<vector<int>> seg = getsegments(a, b);
  for(vector<int> &s : seg)
    upd(s[1], s[0]);
}

ll qrypath(int a, int b){
  if(a == b) return 0;

  ll res = 0;
  vector<vector<int>> seg = getsegments(a, b);
  for(vector<int> &s : seg)
    res += qry(s[1], s[0]);

  return res;
}

signed main(){
  fastio;
  cin >> n >> q;

  G.resize(n+1);
  sub.assign(n+1, 0); // wielkosc poddrzewa
  dist.assign(n+1, 0); // dist od roota
  hpar.assign(n+1, 0); // heavy parent
  hch.assign(n+1, 0); // heavy child
  parent.assign(n+1, 0); // parent
  parc.assign(n+1, 0); // parent
  id.assign(n+1, 0); // preorder
  idod.assign(n+1, 0); // preorder
                       
  tree.assign(2*(1<<(int)ceil(log2(n)))+1, 0);
  lazy.assign(2*(1<<(int)ceil(log2(n)))+1, 0);

  for(int i = 1; i <= n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  
  dfssub(1, 0);

  for(int i = 1; i <= n; i++)
    hpar[i] = i;

  nr = 0;
  dfshld(1, 0);
  
  prefbuild();
  
  ll ans = 0, distances = 0;

  for(int i = 1; i <= q; i++){
    int v; cin >> v;
    // dist(a, b) = dist[a] + dist[b] - 2*dist[lca(a, b)]
    ans += distances + (ll)i*(ll)dist[v] - qrypath(1, v)*(ll)2;
    cout << ans*(ll)2 << "\n";

    distances += (ll)dist[v];
    updpath(1, v);
  }
}
