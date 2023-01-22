// low
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int n, m, id;
vector<vector<pair<int, int>>> G;
vector<int> low, pre, sub, dep;

void dfs(int v, int p){
  pre[v] = low[v] = ++id;
  sub[v] = 1;
  dep[id] = dep[pre[p]]+1;
  
  for(auto &[x, z] : G[v]){
    if(x == p) continue;
    if(low[x]){
      low[v] = min(low[v], pre[x]);
    } else{
      z = 1;
      dfs(x, v);
      sub[v] += sub[x];
      low[v] = min(low[x], low[v]);
    }
  }
}

signed main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);
  low.resize(n+1);
  pre.resize(n+1);
  sub.resize(n+1);
  dep.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back({b, 0});
    G[b].push_back({a, 0});
  }
  id = 0;
  for(int i = 1; i <= n; i++)
    if(!low[i])
      dfs(i, 0);

  int nr = 0;
  
  for(int i = 1; i <= n; i++){
    vector<int> t, u;
    ll smi = 0;
    ll s2 = 0;

    for(auto [x, z] : G[i]){
      if(z){
        if(dep[pre[i]] <= dep[low[x]]){
          smi += (ll)(n-sub[i]) * sub[x];
          t.push_back(sub[x]);
        } else{
          s2 += sub[x];
        }
      }
    }
    ll s = 1;
    ll sumaa = 0;
    for(int k : t)
      sumaa += (ll)k;
    for(int k : t)
      s += (sumaa-(ll)k)*(ll)k;
    s /= 2;
    int _s = s;
    if(t.size() < 2) _s = 0;
    if(t.size() < 1) s = 0;
    cout << 2*_s + 2*(n-1) + 2*smi + 2*s2*sumaa << "\n";
  }
}
