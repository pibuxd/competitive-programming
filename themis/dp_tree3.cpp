#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int n;
ll INF = LONG_LONG_MAX, mn;
vector<vector<int>> G;
vector<int> sub;
vector<ll> kara;

void dfs(int v, int p){
  for(int x : G[v])
    if(x != p){
      dfs(x, v);
      kara[v] += (2 * ((ll)sub[v]-1) + 1) * (ll)sub[x] + kara[x];
      sub[v] += sub[x];
    }
}

void DFS(int v, int p){
  mn = min(mn, kara[v]);
  ll kv = kara[v];
  int sv = sub[v];
  
  for(int x : G[v])
    if(x != p){
      ll kx = kara[x];
      int sx = sub[x];

      kara[v] -= (2*((ll)sub[v]-(ll)sub[x]-1) + 1) * (ll)sub[x] + kara[x];
      sub[v] -= sub[x];

      kara[x] += (2*((ll)sub[x]-1) + 1) * (ll)sub[v] + kara[v];
      sub[x] += sub[v];
      
      DFS(x, v);
      kara[v] = kv, sub[v] = sv;
      kara[x] = kx, sub[x] = sx;
    }
}

signed main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  kara.assign(n+1, 0);
  sub.assign(n+1, 1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);
  mn = INF;
  DFS(1, 0);

  cout << mn << "\n";
}
