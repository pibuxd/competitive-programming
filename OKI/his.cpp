// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  int n;
  const int MOD = 1e9+9;
  vector<vector<int>> G;
  vector<bool> visited;
  stack<int> topSort;

  Graph(int _n){
    n = _n;
    G.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
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
    topSort = stack<int>();
    visited.resize(n+1);
    dfsSortUtil(start);
    visited.clear();
  }

  int numberOfPaths(int start, int end){
    sort(start);
    vector<int> dp(n+1);
    dp[topSort.top()] = 1;

    while(!topSort.empty()){
      int x = topSort.top();
      topSort.pop();

      for(int v : G[x]){
        dp[v] += dp[x];
        dp[v] %= MOD;
      }
    }

    return dp[end];
  }
};

int main(){
  fastio;
  int n, m, start, end;
  cin >> n >> m >> start >> end;

  Graph graph(n);

  for(int a, b; m--;){
    cin >> a >> b;
    graph.push(a, b);
  }

  cout << graph.numberOfPaths(start, end);
}