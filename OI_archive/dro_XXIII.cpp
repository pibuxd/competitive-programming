// * SCC -> DAG + topological sort
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, id;
vector<vector<int>> G, dag, dag2;
vector<int> ids, low, topo;
vector<bool> on_st, vis, exi;
stack<int> st;

void scc(int v){
  st.push(v);
  on_st[v] = true;
  ids[v] = low[v] = id++;

  for(int x : G[v]){
    if(!ids[x]){
      scc(x);
      low[v] = min(low[v], low[x]);
    }
    else if(on_st[x])
      low[v] = min(low[v], low[x]);
  }

  if(ids[v] == low[v])
    for(int node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = low[v];
      if(node == v)
        break;
    }
}

void topo_sort(int v){
  vis[v] = true;
  for(int x : dag[v]){
    if(!vis[x])
      topo_sort(x);
  }

  topo.push_back(v);
}

int main(){
  fastio;
  cin >> n >> m;
  G.assign(n+1, vector<int>());

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  ids.assign(n+1, 0);
  low.assign(n+1, 0);
  id = 1;

  for(int i = 1; i <= n; i++){
    if(!ids[i]){
      st = stack<int>();
      on_st.assign(n+1, false);
      scc(i);
    }
  }

  exi.assign(n+1, false);
  for(int i = 1; i <= n; i++) exi[low[i]] = true;

  dag.assign(n+1, vector<int>());
  dag2.assign(n+1, vector<int>());

  for(int i = 1; i <= n; i++){
    for(int x : G[i]){
      if(low[x] != low[i]){
        dag[low[i]].push_back(low[x]);
        dag2[low[x]].push_back(low[i]);
      }
    }
  }

  vector<bool> ind(n+1, false), outd(n+1, false);  

  for(int i = 1; i <= n; i++)
    for(int x : dag[i])
      ind[x] = true;
  
  vis.assign(n+1, false);
  
  for(int i = 1; i <= n; i++)
    if(!ind[i] && exi[i])
      topo_sort(i);


  // for(int i = 1; i <= n; i++) cout << low[i] << " "; cout << "\n\n";
  // for(int i : topo) cout << i << " "; cout << "\n\n";

  vector<bool> ans(n+1, true);
  
  int licz = 0;  
  vector<bool> czy(n+1, false);
  for(int i : topo){
    czy[i] = true;

    for(int x : dag[i]){
      if(czy[x]){
        licz--;
        czy[x] = false;
      } 
    }
    if(licz > 0){
      // cout << i << " ";
      ans[i] = false;
    }
    licz++;
  }
  // cout << "\nnext\n";
  reverse(topo.begin(), topo.end());
  czy.assign(n+1, false);
  licz = 0;
  for(int i : topo){
    czy[i] = true;

    for(int x : dag2[i]){
      if(czy[x]){
        licz--;
        czy[x] = false;
      } 
    }
    if(licz > 0){
      // cout << i << " ";
      ans[i] = false;
    }
    licz++;
  }
  // cout << "\n";

  int ans_count = 0;
  for(int i = 1; i <= n; i++)
    if(ans[low[i]] && exi[low[i]])
      ans_count++;
  cout << ans_count << "\n";
  if(ans_count == 0) return 0;
  for(int i = 1; i <= n; i++)
    if(ans[low[i]] && exi[low[i]])
      cout << i << " ";
}