#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mid ((l+r)/2)
#define lc (2*v)
#define rc (2*v+1)
#define dlg(l, r) (r-l+1)

struct Node {
  int sum = 0, ls = 0, la = 0;
};

int n, m;
vector<Node> t;
vector<pair<int, int>> maszty;

void push_down(int v, int l, int r){
  t[lc].ls = t[rc].ls = t[v].ls;
  t[lc].la = t[rc].la = t[v].la;
  t[lc].sum = ( (2*t[lc].ls + (dlg(l, mid) - 1) * t[lc].la) * dlg(l, mid) ) / 2;
  t[rc].sum = ( (2*t[rc].ls + (dlg(mid+1, r) - 1) * t[rc].la) * dlg(mid+1, r) ) / 2;
}

void push_up(int v){
  t[v].sum = t[lc].sum + t[rc].sum;
}

void update(int v, int l, int r, int a, int b, int S, int A, int op){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    t[v].ls += S * op;
    t[v].la += A * op;
    t[v].sum = ( (2*t[v].ls + (dlg(l, r) - 1) * t[v].la) * dlg(l, r) ) / 2;
    return;
  }

  push_down(v, l, r);
  update(lc, l, mid, a, b, S, A, op);
  update(rc, mid+1, r, a, b, S+A*((mid+1)-l), A, op);
  push_up(v);
}

int query(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return t[v].sum;
  
  push_down(v, l, r);
  return query(lc, l, mid, a, b) + query(rc, mid+1, r, a, b);
}

int main(){
  fastio;
  cin >> n >> m;
  t.resize(4*(n+1));
  maszty.resize(n+1);

  while(m--){
    char op; cin >> op;
    if(op == 'P'){
      int x, s, a; cin >> x >> s >> a;
      int l = max(1, x-(int)(ceil((float)s / (float)a))+1);
      int r = min(n, x+(int)(ceil((float)s / (float)a))-1);
      update(1, 1, n, l, x, a, a, 1);
      update(1, 1, n, x+1, r, s - a, -a, 1);
      maszty[x] = {s, a};

    } else if(op == 'U'){
      int x; cin >> x; int s = maszty[x].first, a = maszty[x].second;
      int l = max(1, x-(int)(ceil((float)s / (float)a))+1);
      int r = min(n, x+(int)(ceil((float)s / (float)a))-1);
      update(1, 1, n, l, x, a, a, -1);
      update(1, 1, n, x+1, r, s-a, -a, -1);
      maszty[x] = {0, 0};

    } else if(op == 'Z'){
      int a, b; cin >> a >> b;
      cout << query(1, 1, n, a, b) << "\n";
    }
  }
}