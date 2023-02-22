#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lv (2*v)
#define rv (2*v+1)
#define mid ((l+r)/2)

int n, q;
int *t, *a, *c, *wyn;
vector<array<int, 2>> *x;

void upd(int v, int l, int r, int idx, int val){
  if(l == r){
    t[v] = val;
    return;
  }
  if(idx <= mid)
    upd(lv, l, mid, idx, val);
  else
    upd(rv, mid+1, r, idx, val);
  t[v] = min(t[lv], t[rv]);
}

int qry(int v, int l, int r, int L){
  if(l == r) return l;
  if(L > t[lv])
    return qry(lv, l, mid, L);
  else
    return qry(rv, mid+1, r, L);
}

int main(){
  fastio;
  cin >> n;
  a = new int[n+1];
  t = new int[2097153];

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  cin >> q;
  wyn = new int[q+1];
  x = new vector<array<int, 2>>[n+1];

  for(int i = 1; i <= q; i++){
    int l, r; cin >> l >> r;
    x[r].push_back({l, i});
  }
  
  for(int i = 1; i <= n; i++){
    upd(1, 0, n-1, a[i], i);
  
    for(array<int, 2> &X : x[i])
      wyn[X[1]] = qry(1, 0, n-1, X[0]);
  }

  for(int i = 1; i <= q; i++) cout << wyn[i] << "\n";
}
