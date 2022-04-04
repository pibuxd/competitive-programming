// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * find BRIDGES and SCC using function LOW and calculate result
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  int n, pre_num, components;
  vector<vector<int>> G;
  vector<bool> visited;
  vector<int> low, pre, num_of_bridges;
  vector<pair<int, int>> input;
  map<pair<int, int>, int> edges;

  Graph(int _n){
    n = _n;
    G.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
    input.push_back({a, b});
    
    if(edges[{a, b}])
      edges[{b, a}] = 3;
    else
      edges[{a, b}] = 3; // default value = 3, directed: a -> b = 1, a <- b = 2
  }

  void dfs_in_component(int v){
    for(int x : G[v]){
      if(edges[{v, x}] == 3){
        edges[{v, x}] = 1;
        dfs_in_component(x);
      } else if(!edges[{v, x}]){
        edges[{x, v}] = 2;
        dfs_in_component(x);
      }
    }
  }

  void bridge(int a, int b){
    if(edges[{a, b}] && edges[{b, a}])
      return;

    cout << "BRIDGE: " << a << "," << b << endl;
    components += 2;

    if(edges[{a, b}] == 3){
        edges[{a, b}] = 1;
    } else if(!edges[{a, b}]){
        edges[{b, a}] = 2;
    }
    for(int v : G[a]){
      if(edges[{a, v}] == 3){
        edges[{a, v}] = 1;
        dfs_in_component(v);
      } else if(!edges[{a, v}]){
        edges[{v, a}] = 2;
        dfs_in_component(v);
      }
    }

    for(int v : G[b]){
      if(edges[{b, v}] == 3){
        edges[{b, v}] = 1;
        dfs_in_component(v);
      } else if(!edges[{b, v}]){
        edges[{v, b}] = 2;
        dfs_in_component(v);
      }
    }
  }

  void dfs(int v, int parent = -1){
    visited[v] = true;
    pre[v] = low[v] = pre_num++;

    for(int x : G[v]){
      if(x == parent) continue;

      if(visited[x]){
        low[v] = min(low[v], pre[x]);
      } else{
        dfs(x, v);
        low[v] = min(low[v], low[x]);

        if(low[x] > pre[v])
          bridge(v, x);
      }
    }
  }

  void find_bridges_and_components(){
    visited.resize(n+1);
    pre.resize(n+1);
    low.resize(n+1);
    pre_num = components = 0;

    for(int i = 1; i <= n; i++){
      if(!visited[i])
        dfs(i);
    }
  }

  void print(){
    cout << components << "\n";

    for(int i = 1; i <= n; i++){
      
    }
  }
};

int main(){
  fastio;

  int n, m;
  cin >> n >> m;

  Graph graph(n);

  for(int a, b; m--;){
    cin >> a >> b;
    graph.push(a, b);
  }

  graph.find_bridges_and_components();
  graph.print();
}