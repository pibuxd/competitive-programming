// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
  vector<vector<int>> G;
  vector<bool> visited;
  vector<int> low, pre, post, articulations; 
  int n, t, pre_num, post_num;

  Graph(int _n, int _t){
    n = _n;
    t = _t;
    G.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  void is_articulation(int v){
    articulations.push_back(v);
  }

  void dfs(int v, int parent = -1){
    visited[v] = true;
    pre[v] = low[v] = pre_num++;
    int num_of_children = 0;

    for(int x : G[v]){
      if(x == parent) continue;

      if(visited[x]){
        low[v] = min(low[v], pre[x]);
      } else{
        dfs(x, v);
        low[v] = min(low[v], low[x]);

        if(low[x] >= pre[v] && parent != -1){
          is_articulation(v);
        }

        num_of_children++;
      }
    }

    if(parent == -1 && num_of_children > 1 && v != t){
      is_articulation(v);
    }
    
    post[v] = post_num++;
  }

  void find_articulations(){
    visited.resize(n+1);
    pre.resize(n+1);
    post.resize(n+1);
    low.resize(n+1);
    articulations.resize(n+1);

    pre_num = post_num = 0;

    dfs(t);
  }
};

int main(){ // mam pre, post i art -> debug, ...
  fastio;

  int n, m, t;
  cin >> n >> m >> t;

  Graph graph(n, t);

  for(int a, b; m--;){
    cin >> a >> b;
    graph.push(a, b);
  }

  graph.find_articulations();

  for(int x : graph.pre){
    cout << x+1 << ' ';
  } cout << '\n';

  for(int x : graph.post){
    cout << x+1 << ' ';
  } cout << '\n';
  
  for(int x : graph.articulations){
    cout << x << ' ';
  }
}

/*
1 2 3 4 5 6 7 8 9

1 2 3 4 5 6 7 8 9 
9 7 5 4 3 2 1 6 8

1  2 3  4 5 6 7 8 9
0 -1 0  0 0 0 0 1 0



*/