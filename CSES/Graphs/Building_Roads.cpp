#include "bits/stdc++.h"
using namespace std;

int V, E, counter = 0;
vector<vector<int>> G, Trees;
vector<bool> visited;

void DFS(int n, vector<int> &tree){
  visited[n] = true;
  
  for(int x : G[n]){
    if(!visited[x]){
      tree.push_back(x);
      DFS(x, tree);
    }
  }
}

void readGraph(){
  G.resize(V+1);
  for(int i = 0; i < E; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void createTrees(){
  visited.resize(V+1);
  vector<int> tree;

  for(int i = 1; i <= V; i++){
    if(!visited[i]){
      tree.push_back(i);
      DFS(i, tree);
      Trees.push_back(tree);
      tree.clear();
      counter++;
    }
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> V >> E;
  readGraph();
  createTrees();

  cout << counter - 1 << '\n';
  if(counter-1){
    for(int i = 0; i < counter - 2; i++){
      cout << Trees[i][0] << ' ' << Trees[i+1][0] << '\n';
    }
    cout << Trees[counter-1][0] << ' ' << Trees[counter-2][0];
  }
}
