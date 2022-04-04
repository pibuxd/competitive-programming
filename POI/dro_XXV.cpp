// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * SCC + longest path on DAG
#include <bits/stdc++.h>
using namespace std;

long long n, m, id;
vector<vector<long long>> G, dag;
vector<long long> ids, low, dp;
vector<bool> on_st, vis;
stack<long long> st;

void bridge(long long a, long long b){
  dag[low[a]].push_back(low[b]);
}

void dfs(long long v){
  st.push(v);
  on_st[v] = true;
  ids[v] = low[v] = ++id;

  for(long long x : G[v]){
    if(!ids[x]){
      dfs(x);
      low[v] = min(low[v], low[x]);
    }
    else if(on_st[x])
      low[v] = min(low[v], ids[x]);
  }

  if(ids[v] == low[v])
    for(long long node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = ids[v];
      if(node == v)
        break;
    }
}

int dfs2(long long v){
  if(vis[v]) return dp[v];
  vis[v] = true;

  for(long long x : dag[v]){
    dp[v] += dfs2(x);
  }
  return dp[v];
}

int main(){
  cin >> n >> m;
  G.resize(n+1);
  dag.resize(n+1);

  for(long long i = 1; i <= m; i++){
    long long a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  ids.resize(n+1);
  low.resize(n+1);
  id = 0;

  for(long long i = 1; i <= n; i++)
    if(!ids[i]){
      st = stack<long long>();
      on_st.resize(n+1);
      dfs(i);
    }
  
  for(int i = 1; i <= n; i++){
    for(int j : G[i]){
      if(low[j] != low[i]){
        bridge(i, j);
        // cout << "BRIDGE: " << i << " to " << j << "\n";
      }
    }
  }

  dp.resize(n+1);
  // cout << "\n";
  for(long long i = 1; i <= n; i++){
    // cout << i << ": " << low[i] << "\n";
    dp[low[i]]++;
  }

  vector<long long> ind(n+1);
  for(long long i = 1; i <= n; i++){
    sort(dag[i].begin(), dag[i].end());
    dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
    for(long long j : dag[i])
      ind[j]++;
  }
  
  vis.resize(n+1);
  for(long long i = 1; i <= n; i++){
    cout << dfs2(low[i])-1 << "\n";
  }
}