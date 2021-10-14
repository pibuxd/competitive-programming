#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, ans;
vector<vector<ll>> G;
vector<ll> par, black;
vector<bool> color;

void dfs(ll v, ll p){
  for(ll x : G[v]){
    if(x == p) continue;

    par[x] = v;
    dfs(x, v);
  }
}

void add(ll x){
  color[x] = true;
  black[par[x]]++;

  ll neigh = G[x].size();
  ll bl = black[x];
  if(color[par[x]] && x != 1)
    bl++;
  
  ll to_add = neigh - bl;
  
  ans += to_add - 1;
}

void subtract(ll x){
  color[x] = false;
  black[par[x]]--;

  ll neigh = G[x].size();
  ll bl = black[x];
  if(color[par[x]] && x != 1)
    bl++;
  
  ll to_add = neigh - bl;

  ans -= to_add - 1;
}

int main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  black.resize(n+1);
  par.resize(n+1);
  color.resize(n+1);

  for(ll i = 1; i <= n-1; i++){
    ll a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1, 0);

  ans = 1;

  ll m;
  cin >> m;
  while(m--){
    ll z;
    cin >> z;

    if(z > 0)
      add(z);
    else
      subtract(-z);

    cout << ans << "\n";
  }
}