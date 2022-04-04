// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Topological sort in DAG (Directed Acyclic Graph)
// * Known as Kahn's algorithm using BFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
vector<int> indegree, top_sort;

void topological_sort(){
  for(int i = 1; i <= n; i++)
    for(int x : G[i])
      indegree[x]++;

  queue<int> Q;

  for(int i = 1; i <= n; i++)
    if(!indegree[i])
      Q.push(i);
  
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();
    top_sort.push_back(v);

    for(int x : G[v]){
      indegree[x]--;
      if(!indegree[x])
        Q.push(x); 
    }
  }
}

int main(){
  cin >> n >> m;
  G.resize(n+1);
  indegree.resize(n+1);

  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  topological_sort();

  for(int x : top_sort)
    cout << x << " ";
}