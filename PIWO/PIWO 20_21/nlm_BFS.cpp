#include "bits/stdc++.h"
using namespace std;

void readGraph(vector<vector<int>> &G, int n){
  for(int i = 0; i < n - 1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

int maxDist(vector<vector<int>> G, int nsize){
  queue<int> Q;
  int maximum = 1;

  for(int i = 1; i <= nsize; i++){
    vector<bool> visited(nsize+1);
    visited[i] = true;
    Q.push(i);
    vector<int> dist(nsize+1);

    while(!Q.empty()){
      int n = Q.front();
      Q.pop();


      for(int x : G[n]){
        if(!visited[x]){
          visited[x] = true;
          Q.push(x);
          dist[x] = dist[n] + 1;
          if(dist[x] > maximum)
            maximum = dist[x];
        }
      }
    }
  }

  return maximum;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<vector<int>> G(n+1);

  readGraph(G, n);
  cout << maxDist(G, n);
}
