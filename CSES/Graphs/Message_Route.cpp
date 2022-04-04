// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;
//find the shortest path from first node to n-node

const int mxN = 1e5;
int V, E;
vector<vector<int>> G(mxN+1);

void BFS(){
  vector<bool> visited(mxN+1);
  visited[1] = true;
  queue<int> Q;
  Q.push(1);
  int parent[mxN+1];

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();
    if(n == V)
      goto print;

    for(int x : G[n]){
      if(!visited[x]){
        visited[x] = true;
        Q.push(x);

        parent[x] = n;
        if(n == V)
          goto print;
      }
    }
  }
  cout << "IMPOSSIBLE";
  return;

print:
  vector<int> droga;
  int a = V;
  while(a != 1){
    droga.push_back(a);
    a = parent[a];
  }
  droga.push_back(1);
  cout << droga.size() << '\n';
  for(int i = droga.size()-1; i >= 0; i--)
    cout << droga[i] << ' ';
}

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> V >> E;
  
  
  for(int i = 0, a, b; i < E; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }


  BFS();
}
