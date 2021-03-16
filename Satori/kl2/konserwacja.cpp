#include "bits/stdc++.h"
using namespace std;

int V, E, minMOV, lastL;

void readGraph(vector<int> &L, vector<vector<int>> &G, vector<int> &previous){
  vector<bool> hasParent(V+1);

  for(int i = 1; i <= V; i++)
    cin >> L[i];
  for(int i = 0, a, b; i < E; i++){
    cin >> a >> b;
    G[a].push_back(b);
    hasParent[b] = true;
  }
  for(int i = 1; i <= V; i++)
    if(!hasParent[i])
      previous.push_back(i);
}

void minNumMoves(vector<int> &L, vector<vector<int>> &G, int prevL){
  queue<int> Q;
  Q.push();

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : G[v]){

    }
  }
}

int main(void){ ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    minMOV = 0;
    cin >> V >> E;
    vector<int> L(V+1);
    vector<vector<int>> G(V+1);
    vector<int> previous;
    readGraph(L, G, previous);
    vector<bool> visited(V+1);
    lastL = previous[0];
    for(int prevL : previous)
      if(!visited[prevL])
        minNumMoves(L, G, prevL);
  }    
}
