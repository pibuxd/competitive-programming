#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

struct V { ll t, f; };

ll n;
vector<vector<ll>> G, if_f, if_t;
vector<ll> val, use;
vector<V> dp;

void dfs(ll v, ll p){
  for(ll x : G[v]){
    if(x == p) continue;
    dfs(x, v);

    dp[v].t += min(dp[x].f, dp[x].t);
    dp[v].f += dp[x].t;
  }
}

void dfs2(ll v, ll p, bool taken){
  use[v] = taken;
  for(ll x : G[v]){
    if(x == p) continue;
    
    if(taken){
      if(dp[x].f < dp[x].t)
        dfs2(x, v, false);
      else
        dfs2(x, v, true);

    } else{
      dfs2(x, v, true);
    }
  }
}

void solve(){
  cin >> n;
  G.assign(n+1, vector<ll>());
  if_f.assign(n+1, vector<ll>());
  if_t.assign(n+1, vector<ll>());
  val.assign(n+1, 0);
  use.assign(n+1, false);
  dp.assign(n+1, V());

  for(ll i = 1; i <= n; i++){
    cin >> val[i];
    dp[i].t = val[i];
  }

  for(ll i = 1; i <= n-1; i++){
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  dfs(1, -1);
  
  dfs2(1, -1, (dp[1].t < dp[1].f) ? true : false);
  // for(ll i = 1; i <= n; i++) cout << "t , f : " << dp[i].t << " , " << dp[i].f << "\n";
  // cout << "\n";
  cout << min(dp[1].t, dp[1].f) << "\n";
  for(ll i = 1; i <= n; i++)
    cout << use[i];
  cout << "\n";
}

signed main(){
  fastio;
  ll t;
  cin >> t;
  while(t--)
    solve();
}