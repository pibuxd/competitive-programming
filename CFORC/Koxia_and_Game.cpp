#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, M = 998244353;
vector<int> t, te, ts;
vector<bool> tsame;

void makeset(int v){
  t[v] = v, te[v] = 0, ts[v] = 1;
}

int findset(int v){
  if(t[v] == v) return v;
  return t[v] = findset(t[v]);  
}

void mergeset(int a, int b){
  if(a == b) tsame[findset(a)] = true;
  a = findset(a), b = findset(b);
  if(a == b)
    te[a]++;
  else{
    if(ts[a] < ts[b]) swap(a, b);
    t[b] = a;
    ts[a] += ts[b];
    te[a] += te[b] + 1;
    tsame[a] = (tsame[a] || tsame[b]);
  }
}

int solve(){
  cin >> n;
  t.assign(n+1, 0);
  te.assign(n+1, 0);
  ts.assign(n+1, 0);
  tsame.assign(n+1, false);

  vector<int> a(n+1), b(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  for(int i = 1; i <= n; i++)
    makeset(i);

  int sum = 1;
  for(int i = 1; i <= n; i++){
    if(a[i] == b[i])
      sum = (sum * n) % M;
    mergeset(a[i], b[i]);
  }

  vector<bool> vis(n+1, false);

  for(int i = 1; i <= n; i++){
    int p = findset(i);
    if(vis[p]) continue;
    if(te[p] != ts[p]) return 0;
    vis[p] = true;
    if(ts[p] > 1 && !tsame[p])
      sum = (sum * 2) % M;
  }
  return sum;
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
