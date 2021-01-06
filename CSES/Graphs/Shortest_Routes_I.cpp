#include "bits/stdc++.h"
using namespace std;
// Dijkstra

#define ll unsigned long long 
#define uint unsigned long long

const ll INF = 1e17;
const uint mxN = 1e5;
uint V, E;

struct Graph{
  uint neigh;
  uint weight;
};

vector<vector<Graph>> G(mxN+1);

void readG(){
  for(uint i = 0, u, v, c; i < E; i++){
    cin >> u >> v >> c;
    G[u].push_back({v, c});
  }
}

void dijkstra(){
  vector<ll> dist(mxN+1, INF);
  dist[1] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
  Q.push({0, 1});

  while(!Q.empty()){
    uint u = Q.top().second;
    uint d = Q.top().first;
    Q.pop();

    if(dist[u] < d)
      continue;

    for(uint i = 0; i < G[u].size(); i++){
      if(G[u][i].weight+d < dist[G[u][i].neigh]){
        dist[G[u][i].neigh] = G[u][i].weight + d;
        Q.push({dist[G[u][i].neigh], G[u][i].neigh}); 
      } else 
        continue;
    }
  }

  for(uint i = 1; i <= V; i++)
    cout << dist[i] << ' ';
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> V >> E;
  readG();
  dijkstra();
}
