// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

const int mxN = 1e5;
int V, E;
vector<vector<int>> G(mxN+1);

void readG(){
  cin >> V >> E;
  for(int i = 0, a, b; i < E; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void colorG(){
  vector<bool> visited(mxN+1);
  vector<int> color(mxN+1);
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
            cout << "IMPOSSIBLE";
            return;
          }
        } else{
          if(color[v] == 2){
            cout << "IMPOSSIBLE";
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
            cout << "IMPOSSIBLE";
            return;
          }
        } else{
          if(color[v] == 2){
            cout << "IMPOSSIBLE";
            return;
          }
        }
      }
    }
  }
}
  for(int i = 1; i <= V; i++)
    cout << color[i] << ' ';
}

int main(){
  readG();
  colorG();
}
