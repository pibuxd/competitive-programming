#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const ll MOD = 1e9+7, INF = LONG_MAX;
ll n, m;
vector<vector<array<ll, 2>>> G;
vector<array<ll, 2>> parents;
vector<ll> dist, min_len, max_len, comb;

void dijkstra(){
  min_len[1] = 0;
  dist[1] = 0;
  comb[1] = 1;
  priority_queue<array<ll, 2>> Q;
  Q.push({0, 1});

  while(!Q.empty()){
    ll w = -Q.top()[0];
    ll v = Q.top()[1];
    Q.pop();
    
    if(w != dist[v])
      continue;
    
    for(array<ll, 2> x : G[v]){
      if(dist[x[0]] > dist[v] + x[1]){
        dist[x[0]] = dist[v] + x[1];
        Q.push({-dist[x[0]], x[0]});
        min_len[x[0]] = min_len[v] + 1;
        max_len[x[0]] = max_len[v] + 1;
        comb[x[0]] = comb[v];
      }
      else if(dist[x[0]] == dist[v] + x[1]){
        comb[x[0]] = (comb[x[0]] + comb[v]) % MOD;
        min_len[x[0]] = min(min_len[x[0]], min_len[v] + 1);
        max_len[x[0]] = max(max_len[x[0]], max_len[v] + 1);
      }
    }
  }
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  dist.resize(n+1, INF);
  min_len.resize(n+1, INF);
  max_len.resize(n+1);
  comb.resize(n+1);

  for(ll i = 1; i <= m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    if(b == n)
      parents.push_back({a, c});
  }

  dijkstra();
  ll ans_dist, ans_comb = 0, ans_min = INF, ans_max = 0;
  ans_dist = dist[n];

  for(array<ll, 2> p : parents){
    if(dist[p[0]] + p[1] == dist[n]){
      ans_comb = (ans_comb + comb[p[0]] % MOD);
      ans_min = min(ans_min, min_len[p[0]] + 1);
      ans_max = max(ans_max, max_len[p[0]] + 1);
    }
  }

  cout << ans_dist << " " << ans_comb << " " << ans_min << " " << ans_max;
}