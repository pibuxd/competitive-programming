// * finds shortest paths from a starting node to all nodes
// directed or undirected weighted graph, no negative weight edges
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

const long long INF = LONG_MAX;
int n, m;
vector<vector<array<ll, 2>>> G;
vector<array<ll, 2>> dist;

void dijkstra(){
  dist[1] = {0, 0};
  priority_queue<array<ll, 2>> PQ;
  PQ.push({0, 1});

  while(!PQ.empty()){
    ll w = -PQ.top()[0];
    int v = PQ.top()[1];
    PQ.pop();

    if(w != dist[v][0])
      continue;

    for(array<ll, 2> x : G[v]){
      if(dist[x[0]][0] > dist[v][0] + x[1] - dist[v][1]/2 + dist[v][0]){
        dist[x[0]] = {dist[v][0] + x[1] - dist[v][1]/2 + dist[v][1], dist[x[0]][0]};
        PQ.push({-dist[x[0]][0], x[0]});
      }
      else if(dist[x[0]][0] + dist[x[0]][1] - dist[x[0]][1]/2 > dist[v][0] + x[1]/2 - dist[v][1]/2 + dist[v][0]){
        dist[x[0]] = {dist[v][0] + x[1]/2 - dist[v][1]/2 + dist[v][1], x[1]};
        PQ.push({-dist[x[0]][0], x[0]});
      }
      
      
    }
  }
}

int main(){ fastio;
  int m;
  cin >> n >> m;
  G.resize(n+1);
  dist.resize(n+1, {INF, 0});

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
  }

  dijkstra();
  cout << dist[n][0];
}