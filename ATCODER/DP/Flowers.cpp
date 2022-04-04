// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * DP with segment tree
// !it's very typical DP with segment tree problem
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

#define lv (2*v)
#define rv (2*v+1)
#define m ((l+r)/2)

int n;
vector<int> a, h, t, dp;

void insert(int v, int l, int r, int idx, int val){
  if(l == r){
    t[v] = val;
    return;
  }

  if(m >= idx)
    insert(lv, l, m, idx, val);
  else
    insert(rv, m+1, r, idx, val);

  t[v] = max(t[lv], t[rv]);
}

int query(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return t[v];
  
  return max(query(lv, l, m, a, b), query(rv, m+1, r, a, b));
}

signed main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  h.resize(n+1);
  t.resize(4*(n+1));
  dp.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> h[i];
  for(int i = 1; i <= n; i++)
    cin >> a[i];

  for(int i = 1; i <= n; i++){
    dp[i] = query(1, 1, n, 1, h[i]) + a[i];
    insert(1, 1, n, h[i], dp[i]);
  }  

  cout << query(1, 1, n, 1, n);
}