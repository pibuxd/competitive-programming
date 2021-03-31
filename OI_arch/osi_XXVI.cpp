#include <bits/stdc++.h>
using namespace std;
// find bridges

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct hashPair { 
  template <class T1, class T2> 
  size_t operator()(const pair<T1, T2>& p) const
  { 
    auto hash1 = hash<T1>{}(p.first); 
    auto hash2 = hash<T2>{}(p.second); 
    return hash1 ^ hash2; 
  } 
};

struct SCC {
  int N, id, osiedlaCounter;
  vector<vector<int>> G;
  vector<int> low, tin;
  vector<bool> visited;
  vector<pair<int, int>> input;
  unordered_map<pair<int, int>, char, hashPair> edge;

  void init(int _N){
    N = _N;
    osiedlaCounter = 0;
    G = vector<vector<int>>(N+1);
    low = tin = vector<int>(N+1);
    visited = vector<bool>(N+1);
  }

  void push(int a, int b){
    if(!edge[{a, b}]){ // undefine direction
      edge[{a, b}] = '|';
      input.push_back({a, b});
      G[a].push_back(b);
      G[b].push_back(a);
    } else{
      edge[{b, a}] = '|';
      input.push_back({b, a});
    }
  }

  void dfs2(int x, int p = -1){
    visited[x] = true; 

    for(int v : G[x]){
      //cout << x << "->" << v << ' ';

      if(edge[{x, v}] && edge[{v, x}]){
        if(edge[{x, v}] == '|' && edge[{v, x}] == '|'){
          edge[{x, v}] = '>';
          dfs2(v);

        } else if(edge[{x, v}] == '|' && edge[{v, x}] != '|'){
          if(edge[{v, x}] == '>'){
            edge[{x, v}] = '<';

          } else{
            edge[{x, v}] = '>';

          }
          dfs2(v);
        } else if(edge[{x, v}] != '|' && edge[{v, x}] == '|'){
          if(edge[{x, v}] == '>'){
            edge[{v, x}] = '<';

          } else{
            edge[{v, x}] = '>';

          }
          dfs2(v);
        }
      } else if(edge[{x, v}] == '|'){
        edge[{x, v}] = '>';
        dfs2(v); 

      } else if(edge[{v, x}] == '|'){
        edge[{v, x}] = '<';
        dfs2(v);
      }
      
      //else cout << "x ";
    }
  }

  void dfs(int x, int p = 0){
    visited[x] = true;
    tin[x] = low[x] = id++;

    for(int v : G[x]){
      if(v == p){
        continue;
      }
      if(visited[v]){
        low[x] = min(low[x], low[v]);
      } else{
        dfs(v, x);
        low[x] = min(low[x], low[v]);
        
        if(low[v] > tin[x] && !(edge[{x, v}] && edge[{v, x}])){
          osiedlaCounter += 2;
          dfs2(v, x);
          dfs2(x, v);
        }
      }
    }
  }

  void findBridges(){
    id = 1;

    for(int i = 1; i <= N; i++){
      if(!visited[i]){
        dfs(i);
      }
    }
  }

  void print(){
    /*cout << '\n';
    for(int i = 1; i <= N; i++){
      cout << low[i] << ' ';
    }
    cout << "\n\n";*/

    cout << osiedlaCounter << '\n';

    for(auto x : input){
      cout << edge[{x.first, x.second}];
    }
  }
};

int main(){
  fastio;
  int n, m, a, b;
  cin >> n >> m;

  SCC graph;
  graph.init(n);

  while(m--){
    cin >> a >> b;
    graph.push(a, b);
  }

  graph.findBridges();
  graph.print();
}