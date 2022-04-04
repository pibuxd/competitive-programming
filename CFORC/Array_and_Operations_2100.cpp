// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Maximum Bipartite Matching
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m, MX, id, nr;
vector<int> a, c, vis, matched;
vector<array<int, 2>> pary;
vector<vector<int>> G, g;
vector<array<int, 2>> nodes;

bool match(int v){
  if(vis[v] == nr)
    return false;
  vis[v] = nr;

  for(int x : g[v]){
    if(!matched[x] || match(matched[x])){
      matched[x] = v;
      return true;
    }
  }

  return false;
}

int solve(){
  int sum = 0;
  nr = 0;
  matched.assign(id+1, 0);
  vis.assign(id+1, 0);

  for(int i = 1; i <= n; i++){
    for(int j = nodes[i][0]; j <= nodes[i][1]; j++){
      nr++;
      sum += match(j);
    }
  }

  return sum/2;
}

signed main(){
  fastio;
  cin >> n >> m;

  a.resize(n+1);
  c.resize(n+1);
  G.resize(n+1);
  pary.resize(m);

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    MX = max(MX, a[i]);
  }

  for(int i = 0; i < m; i++){
    cin >> pary[i][0] >> pary[i][1];
    G[pary[i][0]].push_back(pary[i][1]);
    G[pary[i][1]].push_back(pary[i][0]);
  }

  int ans = 0;

  // divisors
  for(int d = 2; d*d <= MX; d++){
    nodes.assign(n+1, {0, 0});
    id = 0;

    for(int i = 1; i <= n; i++){
      int ile = 0;

      while(a[i] % d == 0){
        a[i] /= d;
        ile++;
      }

      c[i] = ile;
      if(ile == 0)
        continue;

      nodes[i][0] = ++id;
      nodes[i][1] = id + ile - 1;
      id += ile - 1;
    }

    g.assign(id+1, vector<int>());

    for(int v = 1; v <= n; v++){
      if(!c[v])
        continue;
      for(int x : G[v]){
        if(!c[x])
          continue;

        for(int i = nodes[v][0]; i <= nodes[v][1]; i++){
          for(int j = nodes[x][0]; j <= nodes[x][1]; j++){
            g[i].push_back(j);
            g[j].push_back(i);
          }
        }
      }
    }

    ans += solve();
  }
  
  // prime numbers
  for(int _i = 1; _i <= n; _i++){
    if(a[_i] == 0 || a[_i] == 1) continue;
    int d = a[_i];
    nodes.assign(n+1, {0, 0});
    id = 0;

    for(int i = 1; i <= n; i++){
      int ile = 0;

      while(a[i] % d == 0){
        a[i] /= d;
        ile++;
      }

      c[i] = ile;
      if(ile == 0)
        continue;

      nodes[i][0] = ++id;
      nodes[i][1] = id + ile - 1;
      id += ile - 1;
    }

    g.assign(id+1, vector<int>());

    for(int v = 1; v <= n; v++){
      if(!c[v])
        continue;
      for(int x : G[v]){
        if(!c[x])
          continue;

        for(int i = nodes[v][0]; i <= nodes[v][1]; i++){
          for(int j = nodes[x][0]; j <= nodes[x][1]; j++){
            g[i].push_back(j);
            g[j].push_back(i);
          }
        }
      }
    }

    ans += solve();
  }

  cout << ans;
}