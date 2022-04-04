// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct hash_pair{
  size_t operator()(const pair<int, int>& p) const{
    auto hash1 = hash<int>{}(p.first);
    auto hash2 = hash<int>{}(p.second);
    return hash1 ^ hash2;
  }
};

int n, m, id, counter;
vector<vector<int>> __G, G;
vector<int> low, ids;
vector<pair<int, int>> in;
vector<bool> vis, on_st;
stack<int> st;
unordered_set<pair<int, int>, hash_pair> edges, _in;

void dfs(int v, int p){
  vis[v] = true;
  bool v_doubled = false;

  for(int x : __G[v]){
    if(x == p && !v_doubled) continue;

    if(!v_doubled){
      G[v].push_back(x);
      edges.insert(pair<int, int>({v, x}));
    }
    else{
      G[x].push_back(v);
      edges.insert(pair<int, int>({x, v}));
    }
    v_doubled = true;

    if(!vis[x]){
      dfs(x, v);
    }
  }
}

void scc(int v){
  st.push(v);
  on_st[v] = true;
  ids[v] = low[v] = id++;

  for(int x : G[v]){
    if(!ids[x]){
      scc(x);
      low[v] = min(low[v], low[x]);
    }
    else if(on_st[x]){
      low[v] = min(low[v], low[x]);
    }
  }

  if(low[v] == ids[v]){
    counter++;
    for(int node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = low[v];
      if(node == v)
        break; 
    }
  }
}

int main(){
  fastio;
  cin >> n >> m;
  in.resize(m+1);
  __G.resize(n+1);
  G.resize(n+1);
  vis.resize(n+1, false);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    __G[a].push_back(b);
    __G[b].push_back(a);

    in[i] = {a, b};
  }

  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs(i, 0);

  low.resize(n+1);  
  ids.resize(n+1);
  id = 0;
  counter = 0;

  for(int i = 1; i <= n; i++){
    if(!ids[i]){
      st = stack<int>();
      on_st.assign(n+1, false);
      scc(i);
    }
  }

  cout << counter << "\n";

  for(int i = 1; i <= m; i++){
    if(edges.count(in[i]) && !_in.count(in[i]))
      cout << '>';
    else
      cout << '<'; 
    _in.insert(in[i]);
  }
}