#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;

struct Graph {
  int n;
  vector<vector<int>> G;
  vector<int> longestPaths;

  Graph(int _n){
    n = _n;
    G.resize(n+1);
    longestPaths.resize(n+1);
  }

  void push(int a, int b){
    G[a].push_back(b);
    G[b].push_back(a);
  }

  void initLongestPaths(){
    
  }
};

int main(){
  int n;
  cin >> n;
  
  Graph graph(n);

  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b;
    graph.push(a, b);
  }

  graph.initLongestPaths();

  for(int i = 1; i <= n; i++){
    cout << graph.longestPaths[i];
  }
}