#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, m, id;
vector<vector<int>> G, Grev, Gsc;
vector<int> sc, t, k, ksc;
vector<bool> vis;

void dfs1(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs1(x);
  t.push_back(v);
}

void dfs2(int v){
  vis[v] = true;
  sc[v] = id;
  for(int x : Grev[v])
    if(!vis[x])
      dfs2(x);
}

int bfs(){ // I can because our Gsc is dag created from SCC, otherwise I would use dijkstra
  queue<int> Q;
  vector<int> dist(n+1), ind(n+1);
  for(int i = 1; i <= n; i++)
    for(int v : Gsc[i])
      ind[v]++;

  for(int i = 1; i <= n; i++)
    if(ind[i] == 0){
      Q.push(i);
      dist[i] = ksc[i];
    }

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : Gsc[v]){
      dist[x] = max(dist[x], dist[v] + ksc[x]);
      ind[x]--;
      if(!ind[x])
        Q.push(x);
    }
  }
  return *max_element(all(dist));
}

signed main(){
  fastio;
  cin >> n >> m;

  G.resize(n+1);
  Gsc.resize(n+1);
  Grev.resize(n+1);
  sc.resize(n+1);
  k.resize(n+1);
  ksc.resize(n+1);
  vis.assign(n+1, false);
  
  for(int i = 1; i <= n; i++)
    cin >> k[i];

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    Grev[b].push_back(a);
  }
  
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs1(i);

  reverse(all(t));
  vis.assign(n+1, false);
  id = 0;

  for(int v : t)
    if(!vis[v]){
      id++;
      dfs2(v);
    }

  for(int i = 1; i <= n; i++)
    for(int v : G[i])
      if(sc[i] != sc[v])
        Gsc[sc[i]].push_back(sc[v]);

  for(int i = 1; i <= n; i++)
    ksc[sc[i]] += k[i];

  cout << bfs() << "\n";
}
