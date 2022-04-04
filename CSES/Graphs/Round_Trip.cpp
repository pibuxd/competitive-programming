// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

const int MXN = 1e5;
int V, E, dlg;
vector<vector<int>> G(MXN+1);
vector<bool> visited(MXN+1);
int parent[MXN+1];

void readG(){
  cin >> V >> E;
  for(int i = 0, a, b; i < E; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void printPath(int x, int y){
  vector<int> ans;
  while(y != x){
    ans.push_back(y);
    y = parent[y];
  }
  ans.push_back(x);
  cout << ans.size()+1 << '\n';
  for(int i : ans)
    cout << i << ' ';
  cout << ans[0];

  exit(0);
}

void visit(int v){
  visited[v] = true;
  dlg++;

  for(int x : G[v]){
    if(!visited[x]){
      parent[x] = v;
      visit(x);
    } else if(v != x && parent[v] != x){
      printPath(x, v);
    }
  }
}

void findCycle(){
  for(int v = 1; v <= V; v++)
    if(!visited[v]){
      dlg = 0;
      visit(v);
    }
}

int main(){
  readG();
  findCycle();
  cout << "IMPOSSIBLE";
}
