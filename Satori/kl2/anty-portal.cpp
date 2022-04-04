// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int V, E;

void readG(vector<vector<int>> &G){
  for(int i = 0, a, b; i < E; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void colorG(vector<vector<int>> &G){
  vector<bool> visited(V+1);
  vector<int> color(V+1);
  queue<int> Q;

for(int i = 1; i <= V; i++){
  if(visited[i])
    continue;
  Q.push(i);
  visited[i] = true;
  color[i] = 1;

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : G[v]){
      if(!visited[x]){
        visited[x] = true;
        Q.push(x);

        if(color[x] == 0){
          if(color[v] == 1)
            color[x] = 2;
          else
            color[x] = 1;
        } else if(color[x] == 1){
          if(color[v] == 1){
            cout << "NIE";
            return;
          }
        } else{
          if(color[v] == 2){
            cout << "NIE";
            return;
          }
        }
      }
      if(visited[x]){
        if(color[x] == 0){
          if(color[v] == 1)
            color[x] = 2;
          else
            color[x] = 1;
        } else if(color[x] == 1){
          if(color[v] == 1){
            cout << "NIE";
            return;
          }
        } else{
          if(color[v] == 2){
            cout << "NIE";
            return;
          }
        }
      }
    }
  }
}
  cout << "TAK\n";
  
  if(color[1] == 1)
    cout << "A";
  else 
    cout << "B";

  for(int i = 2; i <= V; i++){
    if(color[i] == 1)
      cout << " A";
    else 
      cout << " B";
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    cin >> V >> E;
    vector<vector<int>> G(V+1);
    readG(G);
    colorG(G);
    cout << '\n';
  } 
}
