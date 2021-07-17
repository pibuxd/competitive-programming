// * Tarjan's algorithm fo SCC (Strongly Connected Components)
// low-link (low) is a value of a node is the lowest node id
// reachable from that node when doing a DFS (including itself)
#include <bits/stdc++.h>
using namespace std;

int n, m, id;
vector<vector<int>> G;
vector<int> ids, low;
vector<bool> on_st;
stack<int> st;

void dfs(int v){
  st.push(v);
  on_st[v] = true;
  ids[v] = low[v] = id++;

  for(int x : G[v]){
    if(!ids[x])
      dfs(x);
    if(on_st[x])
      low[v] = min(low[v], low[x]);
  }

  if(ids[v] == low[v]) // starting point of SCC
    for(int node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = ids[v];
      if(node == v)
        break;
    }
}

int main(){
  cin >> n >> m;
  G.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  ids.resize(n+1);
  low.resize(n+1);
  id = 0;

  for(int i = 1; i <= n; i++)
    if(!ids[i]){
      st = stack<int>();
      on_st.resize(n+1);
      dfs(i);
    }
  
  cout << "\n";
  for(int i = 1; i <= n; i++)
    cout << i << ": " << low[i] << "\n";
  
  /*
  example input:
  1 2
  2 3
  3 1
  3 4
  4 5
  5 4
  */
}