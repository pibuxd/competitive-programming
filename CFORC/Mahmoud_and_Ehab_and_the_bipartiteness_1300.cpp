// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;

void bfs(vector<vector<int>> &G, vector<bool> &color){
  queue<int> Q;
  vector<bool> visited(n+1);
  Q.push(1);
  visited[1] = true;
  color[1] = 1;

  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : G[v]){
      if(!visited[x]){
        visited[x] = true;
        Q.push(x);
        color[x] = !color[v];
      }
    }
  }
}

int main(){
  fastio;
  cin >> n;

  vector<vector<int>> G(n+1);

  for(int i = 1; i <= n - 1; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  vector<bool> color(n+1);
  bfs(G, color);

  long long ca = 0, cb = 0;
  for(int i = 1; i <= n; i++){
    if(!color[i]) ca++;
    else cb++;
  }

  cout << ca*cb - (n-1);
}