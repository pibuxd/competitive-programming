// * finds shortest paths from a starting node to all nodes
// directed or undirected weighted graph, no negative weight edges
#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_MAX;
int n, m;
vector<vector<pair<int, long long>>> G;
vector<int> parent;
vector<long long> dist;

void dijkstra(int start){
  dist[start] = 0;
  priority_queue<pair<long long, int>> PQ;
  PQ.push({0, start});

  while(!PQ.empty()){
    long long w = -PQ.top().first;
    int v = PQ.top().second;
    PQ.pop();

    if(w != dist[v])
      continue;

    for(auto x : G[v]){
      if(dist[x.first] > dist[v] + x.second){
        dist[x.first] = dist[v] + x.second;
        parent[x.first] = v;
        PQ.push({-dist[x.first], x.first});
      }
    }
  }
}

int main(){
  int start = 1; // starting node
  cin >> n >> m;
  G.resize(n+1);
  parent.resize(n+1);
  dist.resize(n+1, INF);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    //G[b].push_back({a, w});
  }

  dijkstra(start);
}