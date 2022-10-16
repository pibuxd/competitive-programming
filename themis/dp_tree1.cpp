// find shortest distance such as node v is centrum of an tree
#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, INF = LONG_LONG_MAX;
vector<vector<pair<int, int>>> G;
vector<int> sub, up, subsize;

void dfssub(int v, int p){
  subsize[v] = 1;
  for(auto [x, w] : G[v]){
    if(x == p) continue;
    dfssub(x, v);
    sub[v] += sub[x] + (subsize[x] * w);
    subsize[v] += subsize[x];
  }
}

void dfsup(int v, int p, int dvp){
  if(v != 1){
    int subp = sub[p] - (sub[v] + subsize[v] * dvp);
    up[v] = up[p] + subp + (n-subsize[v])*dvp;
  }

  for(auto [x, w] : G[v]){
    if(x == p) continue;
    dfsup(x, v, w);
  }
}

signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;

  G.resize(n+1);
  sub.resize(n+1, 0);
  subsize.resize(n+1, 0);
  up.resize(n+1, 0);
  
  for(int i = 1; i <= n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  dfssub(1, 0);
  dfsup(1, 0, 0);
  
  int ans = INF;
  for(int i = 1; i <= n; i++)
    ans = min(ans, up[i] + sub[i]);
  cout << ans << "\n";
  
  /*
  for(int i = 1; i <= n; i++) cout << sub[i] << " ";
  cout << "\n";
  for(int i = 1; i <= n; i++) cout << up[i] << " ";
  cout << "\n";
  */
}
