// * find bridges using function LOW and calculate result
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  int n, pre_num;
  vector<vector<int>> G;
  vector<bool> visited;
  vector<int> low, pre, num_of_bridges;

  Graph(int _n){
    n = _n;
    G.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  void bridge(int a, int b){
    num_of_bridges[a]++,num_of_bridges[b]++;
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

  void find_bridges(){
    visited.resize(n+1);
    pre.resize(n+1);
    low.resize(n+1);
    num_of_bridges.resize(n+1);

    pre_num = 0;

    for(int i = 1; i <= n; i++){
      if(!visited[i])
        dfs(i);
    }
  }

  int ans(){
    int num = 0;
    for(int i = 1; i <= n; i++){
      if(num_of_bridges[i] == 1){
        num++;
      }
    }
    if(num%2){
      return num/2+1;
    }
    return num/2;
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

  graph.find_bridges();
  cout << graph.ans();
}