#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

ll n, k;
vector<vector<ll>> G;
vector<ll> dist, sub;

void dfs(ll v, ll p, ll d){
  dist[v] = d;
  sub[v] = 1;
  for(ll x : G[v]){
    if(x != p){
      dfs(x, v, d+1);
      sub[v] += sub[x];
    }
  }  
}

int main(){
  fastio;
  cin >> n >> k;

  G.resize(n+1);
  dist.resize(n+1);
  sub.resize(n+1);

  for(ll i = 1; i <= n - 1; i++){
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0, 0);

  vector<ll> ans(n);
  for(ll i = 0; i < n; i++){
    ans[i] = dist[i+1] - sub[i+1] + 1;
  }
  sort(ans.begin(), ans.end(), greater<ll>());
  ll sum = 0;
  for(ll i = 0; i < k; i++){
    sum += ans[i];
  }

  cout << sum;
}