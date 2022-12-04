#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define m ((l+r)/2)
#define lv (2*v)
#define rv (2*v+1)

const int mxn = 2*1e5;
int n;
pair<int, int> A[mxn+1];
int a[mxn+1], tree[524289];
vector<pair<int, int>> V[mxn+1];

void fastscan(int &num) {
  int c = getchar_unlocked();

  while(!('0' <= c && c <= '9')) 
    c = getchar_unlocked();

  num = 0;
  while('0' <= c && c <= '9') {
    num = (num << 1) + (num << 3) + (c - '0');
    c = getchar_unlocked();
  }
}

void upd(int v, int l, int r, int idx, int val){
  if(l == r){
    tree[v] = val;
    return;
  }
  if(idx <= m) upd(lv, l, m, idx, val);
  else upd(rv, m+1, r, idx, val);
  tree[v] = max(tree[lv], tree[rv]);
}

int qry(int v, int l, int r, int idx){
  if(r <= idx) return 0;
  if(l > idx) return tree[v];
  return max(qry(lv, l, m, idx), qry(rv, m+1, r, idx));
}

signed main(){
  fastio;
  int t; fastscan(t);

  while(t--){
    fastscan(n);
    for(int i = 1; i <= n; i++){
      fastscan(a[i]);
      A[i] = {a[i], i};
    }
    sort(A, A+n+1);
    int N = 0;
    for(int i = 1; i <= n; i++){
      if(A[i-1].first != A[i].first)
        a[A[i].second] = ++N;
      else 
        a[A[i].second] = N;
    }

    //vector<vector<pair<int, int>>> V(N+1, {{0, n+1}});
    for(int i = 1; i <= N; i++){
      V[i].clear();
      V[i].push_back({0, n+1});
    }
    int curr = N+1, len = 0;
    for(int i = n; i >= 1; i--){
      if(a[i] < curr) len++;
      else len = 1;
      curr = a[i];
      V[a[i]].push_back({len, i});
    }
    for(int i = 1; i <= N; i++){
      sort(all(V[i]));
      upd(1, 1, N, i, V[i].back().first);
    }

    curr = 0, len = 0;
    int ans = qry(1, 1, N, 0);
    for(int i = 1; i <= n; i++){
      while(V[a[i]].back().second <= i)
        V[a[i]].pop_back();
      upd(1, 1, N, a[i], V[a[i]].back().first);
      
      if(a[i] > curr) len++;
      else len = 1;
      curr = a[i];
      ans = max(ans, qry(1, 1, N, a[i])+len);
    }
    cout << ans << "\n";
  }
}
