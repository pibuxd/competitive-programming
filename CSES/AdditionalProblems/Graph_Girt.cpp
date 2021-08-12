// * Cycle find
// * BFS
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int INF = INT_MAX;
int n, m, ans = INF;
vector<vector<int>> G;

void bfs(int start){
  vector<int> par(n+1);
  vector<int> dist(n+1);
  vector<bool> vis(n+1);
  queue<int> Q;

  dist[start] = 0;
  vis[start] = true;
  Q.push(start);
  
  int len = INF;
  while(!Q.empty()){
    int v = Q.front();
    Q.pop();

    for(int x : G[v]){
      if(!vis[x]){
        vis[x] = true;
        Q.push(x);
        dist[x] = dist[v] + 1;
        par[x] = v;
      }
      else if(par[v] != x)
        len = min(len, dist[v] + dist[x] + 1);
    }
  }

  ans = min(ans, len);
}

int main(){
  fastio;
  cin >> n >> m;
  G.resize(n+1);

  while(m--){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    bfs(i);
  }

  if(ans == INF)
    ans = -1;
  
  cout << ans;
}