// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// Tarjan's SCC
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

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

  if(ids[v] == low[v]) // check if it is starting point of SCC
    for(int node = st.top();; node = st.top()){
      st.pop();
      on_st[node] = false;
      low[node] = ids[v];
      if(node == v)
        break;
    }
}

int main(){
  fastio;
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
  
  /*
  cout << "\n";
  for(int i = 1; i <= n; i++)
    cout << i << ": " << low[i] << "\n";
  */

  map<int, int> ans;
  int temp = 1, number_of_scc = 0;
  for(int i = 1; i <= n; i++)
    if(!ans[low[i]])
      ans[low[i]] = temp, temp++, number_of_scc++;
  
  cout << number_of_scc << "\n";
  for(int i = 1; i <= n; i++)
    cout << ans[low[i]] << " ";
}