// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  int n;
  vector<vector<int>> G;
  vector<bool> visited;
  stack<int> topSort;

  Graph(int _n){
    n = _n;
    G.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  void dfsSortUtil(int x){
    visited[x] = true;

    for(int v : G[x]){
      if(!visited[v]){
        dfsSortUtil(v);
      }
    }

    topSort.push(x);
  }

  void sort(int start){
    visited.resize(n+1);
    dfsSortUtil(start);
  }

  void print(){
    vector<bool> _visited(n+1);
    topSort = stack<int>();

    for(int i = 1; i <= n; i++){
      for(int x : G[i]){
        _visited[x] = true;
      }
    }
    
    for(int i = 1; i <= n; i++){
      if(!_visited[i]){
        sort(i);
      }
    }

    while(!topSort.empty()){
      cout << topSort.top() << ' ';
      topSort.pop();
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

  graph.print();
}