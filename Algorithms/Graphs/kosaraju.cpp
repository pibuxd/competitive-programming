#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G, Grev;
vector<bool> vis;
vector<int> order, component;

void dfs1(int v){
  vis[v] = true;
  for(int x : G[v])
    if(!vis[x])
      dfs1(x);
  order.push_back(v);
}

void dfs2(int v){
  vis[v] = true;
  component.push_back(v);
  
  for(int x : Grev[v])
    if(!vis[x])
      dfs2(x);
}

int main(){
  cin >> n >> m;
  G.resize(n+1);
  Grev.resize(n+1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    Grev[b].push_back(a);
  }

  vis.assign(n+1, false);
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      dfs1(i);

  vis.assign(n+1, false);
  reverse(order.begin(), order.end());

  vector<int> scc(n+1);
  int id = 0;

  for(int o : order){
    if(!vis[o]){
      dfs2(o);
      id++;
      for(int c : component)
        scc[c] = id;
      component.clear();
    }
  }

  cout << id << "\n";
  for(int i = 1; i <= n; i++)
    cout << scc[i] << " ";
  cout << "\n";
}
