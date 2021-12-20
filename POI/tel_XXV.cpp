#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define lv (2*v)
#define rv (2*v+1)
#define m ((l+r)/2)

struct Node {
  int v = 0, lza = 0, lzq = 0;
};

int n, q;
vector<Node> t;
vector<array<int, 2>> maszty;

int an(int a, int q, int i){
  return a + q*(i-1);
}

int sn(int len, int a, int q){
  return ( ( 2*a + (len-1)*q ) * (len) ) / 2;
}

void push_up(int v){
  t[v].v = t[lv].v + t[rv].v;
}

void push_down(int v, int l, int r){
  if(t[v].lza == 0 && t[v].lzq == 0)
    return;

  int A = t[v].lza;
  int Q = t[v].lzq;
  int _A = an(A, Q, m+1-l+1);

  t[lv].lza += A;
  t[lv].lzq += Q;
  t[rv].lza += _A;
  t[rv].lzq += Q;
 
  t[lv].v += sn(m-l+1, A, Q);
  t[rv].v += sn(r-m-1+1, _A, Q);

  t[v].lza = t[v].lzq = 0;
}

void upd(int v, int l, int r, int a, int b, int A, int Q){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    int __t = t[v].v;

    int _A = an(A, Q, l-a+1);
    t[v].lza += _A;
    t[v].lzq += Q;
    t[v].v += sn(r-l+1, _A, Q);
    return;
  } 

  push_down(v, l, r);
  upd(lv, l, m, a, b, A, Q);
  upd(rv, m+1, r, a, b, A, Q);
  push_up(v);
}

void upd(int x, int a, int q){
  int zl = a / q;
  int zr = a / q;

  if(x - zl < 1)
    zl = x-1;
  if(x + zr > n)
    zr = n-x;

  int L = x - zl;
  int R = x + zr;
  int end_val_l = a - (q * zl);
  upd(1, 1, n, L, x, end_val_l, q);
  if(R > x)
    upd(1, 1, n, x+1, R, a-q, -q);
}

int qry(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return t[v].v;
  
  push_down(v, l, r);
  return qry(lv, l, m, a, b) + qry(rv, m+1, r, a, b);
}

int qry(int a, int b){
  return qry(1, 1, n, a, b) / (b-a+1);
}

signed main(){
  fastio;
  cin >> n >> q;
  maszty.resize(n+1);
  t.resize(4*(n+1));

  while(q--){
    char op; cin >> op;
    
    if(op == 'P'){
      int x, a, q; cin >> x >> a >> q;
      maszty[x] = {a, q}; 
      upd(x, a, q);

    } else if(op == 'U'){
      int x; cin >> x;
      int a = maszty[x][0], q = maszty[x][1];
      upd(x, -a, -q);

    } else{
      int x1, x2; cin >> x1 >> x2;
      cout << qry(x1, x2) << "\n";
    }
  }
}