// * finds shortest paths from a starting node to all nodes and detect negative cycle in the graph
// directed weighted graph
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<pair<int, int>>> G;
vector<int> dist, parent;

void negative_cycle(int a, int b){
  cout << "Graph contains a negative-weight cycle from " << a << "to " << b;
}

void bellman_ford(int start){
  dist[start] = 0;
  
  for(int it = 1; it <= n - 1; it++)
    for(int i = 1; i <= n; i++){
      for(auto x : G[i]){
        if(dist[i] + x.second < dist[x.first]){
          dist[x.first] = dist[i] + x.second;
          parent[x.first] = i;
        }
      }
    }

  // check for negative-weight cycles
  for(int i = 1; i <= n; i++){
    for(auto x : G[i]){
      if(dist[i] + x.second < dist[x.first]){
        negative_cycle(i, x.first);
      }
    }
  }
}

int main(){
  int start; // starting node
  cin >> n >> m >> start;
  G.resize(n+1);
  parent.resize(n+1);
  dist.resize(n+1, INF);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
  }

  bellman_ford(start);
}