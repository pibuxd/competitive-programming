#include "bits/stdc++.h"
using namespace std;

void readGraph(vector<vector<int>> &G, int m){
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

bool canPlant(vector<vector<int>> G, int nsize){
  vector<bool> visited(nsize+1), kwiat(nsize+1);
  queue<int> Q;

  for(int i = 1; i <= nsize; i++){
    if(!visited[i]){
      visited[i] = true;
      Q.push(i);

      while(!Q.empty()){
        int n = Q.front();
        Q.pop();

        for(int x : G[n]){
          if(!visited[x]){
            visited[x] = true;
            Q.push(x);

            if(kwiat[n])
              kwiat[x] = false;
            else
              kwiat[x] = true;
          }
        }
      }
    }
  }

  for(int i = 1; i <= nsize; i++){
    for(int x : G[i]){
      if(kwiat[i] == kwiat[x])
        return false;
    }
  }

  return true;
}

int main(){
  int n, m; cin >> n >> m;

  vector<vector<int>> G(n+1);
  readGraph(G, m);

  if(canPlant(G, n))
    cout << "TAK\n";
  else
    cout << "NIE\n";

}
