#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// Tarjan's SCC

struct SCC {
  int N, id;
  vector<vector<int>> G;
  stack<int> S;
  vector<bool> onStack;
  vector<int> visited, low, bel;
  
  void init(int _N){
    N = _N;
    G.resize(N+1);
    visited.resize(N+1);
    low.resize(N+1);
    bel.resize(N+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
  }

  void dfs(int x){
    S.push(x);
    onStack[x] = true;
    
    visited[x] = low[x] = id++;

    for(int v : G[x]){
      if(!visited[v]){
        dfs(v);
      }
      if(onStack[v]){
        low[x] = min(low[v], low[x]);
      }
    }

    if(visited[x] == low[x]){
      for(int node = S.top(); ; node = S.top()){
        S.pop();
        onStack[node] = false;
        low[node] = visited[x];

        if(node == x){
          break;
        }
      }
    }
  }

  void generate(){
    id = 1;

    for(int i = 1; i <= N; i++){
      if(!visited[i]){
        S = stack<int>();
        onStack.resize(N+1);
        dfs(i);
      }
    }
  }

  void print(){
    int idx = 0;

    for(int i = 1; i <= N; i++){
      if(!bel[low[i]]){
        idx++;
        bel[low[i]] = idx;
      }
    }

    cout << idx << '\n';
    for(int i = 1; i <= N; i++){
      cout << bel[low[i]] << ' ';
    }
  }
};

int main(){
  fastio;
  int n, m;
  cin >> n >> m;
  
  SCC graph;
  graph.init(n);

  while(m--){
    int a, b;
    cin >> a >> b;
    graph.push(a, b);
  }

  graph.generate();
  graph.print();
}