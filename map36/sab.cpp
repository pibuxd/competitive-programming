#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, id;
vector<vector<int>> G, G2;
vector<int> ids, low;
vector<bool> onstack;
stack<int> s;

void dfs(int v){
  s.push(v);
  onstack[v] = true;
  low[v] = ids[v] = id++;

  for(int x : G[v]){
    if(!ids[x]){
      dfs(x);
      low[v] = min(low[v], low[x]);
    } else if(onstack[x]){
      low[v] = min(low[v], ids[x]);
    }
  }

  if(low[v] == ids[v])
    for(int x = s.top(); ; x = s.top()){
      s.pop();
      onstack[x] = false;
      low[x] = low[v];
      if(x == v)
        break;
    }
}

vector<bitset<50005>> dist;
vector<bool> vis;

void dfs2(int v){
  vis[v] = true;
  dist[v][v] = true;

  for(int x : G2[v]){
    if(!vis[x])
      dfs2(x);
    dist[v] |= dist[x];
  } 
}

int main(){
  fastio;
  int m, q;
  cin >> n >> m >> q;

  G.resize(n+1);
  G2.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    //G[b].push_back(a);
  }

  ids.resize(n+1);
  low.resize(n+1);
  onstack.resize(n+1);
  id = 0;
  for(int i = 1; i <= n; i++)
    if(!ids[i])
      dfs(i);
    
  map<pair<int, int>, bool> M;
  for(int i = 1; i <= n; i++){
    for(int x : G[i]){
      if(low[i] != low[x] && !M[{low[i], low[x]}]){
        G2[low[i]].push_back(low[x]);
        M[{low[i], low[x]}] = true;
      }
    }
  }
  
  vector<int> ind(n+1);
  vis.resize(n+1);
  dist.resize(n+1);
  for(int i = 1; i <= n; i++)
    for(int x : G2[i])
      ind[x]++;

  for(int i = 1; i <= n; i++)
    if(ind[i] == 0)
      dfs2(i);

  while(q--){
    int a, b; cin >> a >> b;
    if(dist[low[a]][low[b]] == true)
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
