#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  int n, m, sum;
  vector<vector<int>> G;
  vector<bool> cat, visited;

  Graph(int _n, int _m){
    n = _n;
    m = _m;
    G.resize(n+1);
    cat.resize(n+1);
  }

  void set_cat(int i, bool is_cat){
    cat[i] = is_cat;
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  void dfs(int v, int cats){
    visited[v] = true;
    bool is_leaf = true;

    for(int x : G[v]){
      if(!visited[x]){
        if(!cat[x]){
          dfs(x, 0);
        } else{
          if(cats < m) dfs(x, cats+1);
        }
        is_leaf = false;
      }
    }

    if(is_leaf) sum++;
  }

  int ans(){
    sum = 0;
    visited.resize(n+1);

    if(cat[1])
      dfs(1, 1);
    else 
      dfs(1, 0);
    
    return sum;
  }
};

int main(){
  fastio;
  int n, m;
  cin >> n >> m;

  Graph graph(n, m);

  for(int i = 1; i <= n; i++){
    int a;
    cin >> a;
    graph.set_cat(i, a);
  }

  for(int i = 1; i <= n-1; i++){
    int a, b;
    cin >> a >> b;
    graph.push(a, b);
  }

  cout << graph.ans();
}