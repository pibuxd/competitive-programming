#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m, k, INF = 1e8;
vector<vector<int>> G, dist;
map<pair<int, int>, int> wyr;

pair<int, int> pa(int a, int b){
  return {min(a, b), max(a, b)};
}

void bfs(){
  queue<pair<int, int>> Q;
  dist[1][0] = 0;
  Q.push({1, 0});

  while(!Q.empty()){
    auto [v, usedk] = Q.front();
    Q.pop();

    for(int x : G[v]){
      bool iw = (wyr[pa(v, x)] == 1);
      if(iw && usedk < k && dist[v][usedk] + 1 < dist[x][usedk+1]){
        dist[x][usedk+1] = dist[v][usedk] + 1;
        Q.push({x, usedk+1});
      } else if(!iw && dist[v][usedk] + 1 < dist[x][usedk]){
        dist[x][usedk] = dist[v][usedk] + 1;
        Q.push({x, usedk});
      }
    }
  }
}

int main(){
  fastio;
  cin >> n >> m >> k;

  G.resize(n+1);
  dist.assign(n+1, vector<int>(k+1, INF));
  
  for(int i = 1; i <= m; i++){
    int a, b, p; cin >> a >> b >> p;
    G[a].push_back(b);
    G[b].push_back(a);
    if(p == 1){
      if(wyr[pa(a, b)] != -1)
        wyr[pa(a, b)] = 1;
    } else{
      wyr[pa(a, b)] = -1;
    }
  }

  bfs();

  int mn = INF;
  for(int i = 0; i <= k; i++)
    mn = min(dist[n][i], mn);
  cout << (mn == INF ? -1 : mn) << "\n";
}
