// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// find union na krawedziach
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, k, pkts;
vector<int> par, dot;

bool e(int x, int y){
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void make_set(int v){
  bool czy_dot = false;
  if(v % (n+1) == 1 || v % (n+1) == 0) czy_dot = true;
  else if(v <= (n+1)) czy_dot = true;
  else if(v >= m*(n+1)+1) czy_dot = true;

  par[v] = v;
  dot[v] = czy_dot;
}

int kr(int x, int y, int a, int b){
  if(y > b) return 0;
  if(x < a) return 1;
  if(y < b) return 2;
  return 3; // x > a
}

int find_set(int v){
  if(v == par[v]) return v;
  return par[v] = find_set(par[v]);
}

bool czy_pkt_dot(int v){
  v = find_set(v);
  return dot[v];
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);

  if(a != b){
    par[b] = par[a];
    dot[b] = dot[a] = (dot[a] || dot[b]);
  }
}

int pkt(int x, int y, int it){
  if(it == 0 || it == 1) return (y-1)*(n+1) + x + it;
  if(it == 2) return pkt(x, y+1, 1);
  return pkt(x, y+1, 0); // it == 3
}

bool add_kraw(int x, int y, int a, int b){
  int gd = kr(x, y, a, b);

  int pk1 = pkt(x, y, gd);
  int pk2 = pkt(x, y, (gd+1)%4);
  // cout << "PKT: " << pk1 << ", " << pk2 << ",, " << czy_pkt_dot(pk1) << ", " << czy_pkt_dot(pk2) << "\n";

  if(czy_pkt_dot(pk1) && czy_pkt_dot(pk2))
    return false;

  union_sets(pk1, pk2);
  return true;
}

int main(){
  fastio;
  cin >> n >> m >> k;
  pkts = (n+1) * (m+1);

  par.resize(pkts+1);
  dot.resize(pkts+1);

  for(int i = 1; i <= pkts; i++)
    make_set(i);

  // for(int i = 1; i <= m; i++){
  //   for(int j = 1; j <= n; j++)
  //     cout << pkt(j, i, 1) << " ";
  //   cout << "\n";
  // }
  // cout << pkts()

  while(k--){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    
    bool ok = add_kraw(x, y, a, b);

    if(ok) cout << "TAK\n";
    else cout << "NIE\n";
  }
}