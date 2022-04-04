// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, ans;
vector<vector<array<ll, 2>>> G;
vector<ll> a;

void dfs(int v, int dist){
  if(dist > a[v])
    return;
  ans++;

  for(auto node : G[v]){
    ll x = node[0], c = node[1];
    dfs(x, max(0LL, dist+c));
  }
}

int main(){
  fastio;
  cin >> n; 
  G.assign(n+1, vector<array<ll, 2>>());
  a.assign(n+1, 0);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  for(int i = 2; i <= n; i++){
    ll x, c;
    cin >> x >> c;
    G[x].push_back({i, c});
  }

  dfs(1, 0);
  cout << n-ans;
}