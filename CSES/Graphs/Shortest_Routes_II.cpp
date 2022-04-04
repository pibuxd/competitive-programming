// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;
// Floyd-Warshall

// speed up
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define ll unsigned long long

const ll INF = 500e9+1;
const ll MXN = 500;
ll V, E, T;
vector<vector<ll>> dist(MXN+1, vector<ll>(MXN+1, INF));

void readDist(){
  for(ll i = 0, u, v, w; i < E; i++){
    cin >> u >> v >> w;
    dist[u][v] = min(dist[u][v], w);
    dist[v][u] = min(dist[v][u], w);
    dist[u][u] = 0; dist[v][v] = 0;
  }
}

void floydWarshall(){
  for(int k = 1; k <= V; k++)
    for(int i = 1; i <= V; i++)
      for(int j = 1; j <= V; j++)
        if(dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
}

void testIn(){
  int a, b;
  while(T--){
    cin >> a >> b;
    if(dist[a][b] != INF)
      cout << dist[a][b] << '\n';
    else
      cout << "-1" << '\n';
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  cin >> V >> E >> T;
  readDist();
  floydWarshall();
  testIn();
}
