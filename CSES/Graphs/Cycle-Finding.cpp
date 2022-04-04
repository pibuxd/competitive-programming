// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int node, weight;
};

struct Graph {
  int N;
  vector<vector<Edge>> G;
  vector<bool> visited, visited2;
  vector<int> parent;
  int cycle;

  Graph(int _N){
    N = _N;
    G.resize(N+1);
  }

  void push(int a, int b, int w){
    G[a].push_back({b, w});
  }

  void cycleValidation(int x, int end){
    long long sum = 0;
    vector<int> cycle;

    cycle.push_back(end);
    sum += G[x][end].weight;

    while(parent[x] != end){
      cycle.push_back(x);
      sum += G[parent[x]][x].weight;
      x = parent[x];
    }
    
    cycle.push_back(x);
    cycle.push_back(end);
    sum += G[end][x].weight;

    if(sum < 0){
      cout << "YES\n";

      for(int c : cycle){
        cout << c << ' ';
      }

      exit(0);
    }
  }

  void dfs(int x){
    visited[x] = visited2[x] = true;

    for(Edge v : G[x]){
      if(!visited[v.node]){
        parent[v.node] = x;
        dfs(v.node);
      } else{
        cycleValidation(x, v.node);
      }
    }

  }

  void printNegativeCycle(){
    visited2.resize(N+1);

    for(int i = 1; i <= N; i++){
      if(!visited2[i]){
        visited.resize(N+1);
        parent.resize(N+1);
        dfs(i);
      }
    }
  }
};

int main(){
  int n, m, a, b, w;
  cin >> n >> m;
  
  Graph graph(n);

  while(m--){
    cin >> a >> b >> w;
    graph.push(a, b, w);
  }

  graph.printNegativeCycle();
  cout << "NO";
}