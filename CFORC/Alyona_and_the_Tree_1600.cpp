#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const ll INF = LONG_MAX; 
ll n, ans;
vector<vector<array<ll, 2>>> G;
vector<ll> dist, mn, a, sub;

void dfs(int v){
  for(auto node : G[v]){
    ll x = node[0], c = node[1];

    dist[x] = dist[v] + c;
    mn[x] = min(mn[v], dist[x]);
    dfs(x);
    sub[v] += sub[x] + 1;
  }
}

void dfs2(int v){
  for(auto node : G[v]){
    ll x = node[0], c = node[1];

    if(dist[x] - mn[x] > a[x]){
      ans += sub[x] + 1;
    }
    else{
      dfs2(x);
    }
  }
}

int main(){
  fastio;
  cin >> n; 
  G.assign(n+1, vector<array<ll, 2>>());
  dist.assign(n+1, 0);
  mn.assign(n+1, 0);
  sub.assign(n+1, 0);
  a.assign(n+1, 0);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  for(int i = 2; i <= n; i++){
    ll x, c;
    cin >> x >> c;
    G[x].push_back({i, c});
  }

  dfs(1);

  ans = 0;
  dfs2(1);

  // for(int i = 1; i <= n; i++)
  //   cout << sub[i] << " ";
  // cout << "\n";

  cout << ans;
}