#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n;
vector<ll> ans;
vector<vector<ll>> G;
vector<map<ll, ll>> M;

void dfs(ll v, ll p){
  for(ll x : G[v]){
    if(x != p){
      dfs(x, v);
      ll a = v, b = x;

      if(M[a].size() < M[b].size())
        swap(M[a], M[b]);
      for(auto i : M[b])
        M[a][i.first] += i.second;
    }
  }

  auto it = M[v].begin();
  while(true){
    ans[v] += it->first;
    ll temp = it->second;
    it++;
    if(it->second < temp || it == M[v].end())
      break;
  }
}

int main(){
  fastio;
  cin >> n;

  ans.resize(n+1);
  G.resize(n+1);
  M.resize(n+1);
  
  for(ll i = 1; i <= n; i++){
    ll c;
    cin >> c;
    M[i][c] = 1;
  }

  for(ll i = 1; i <= n-1; i++){
    ll a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  dfs(1, 0);

  for(ll i = 1; i <= n; i++)
    cout << ans[i] << " ";
}