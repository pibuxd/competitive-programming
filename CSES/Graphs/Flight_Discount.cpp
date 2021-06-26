// * finds shortest paths from a starting node to all nodes
// directed or undirected weighted graph, no negative weight edges
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const long long INF = LONG_MAX;
int n;
vector<vector<pair<int, long long>>> G;
vector<long long> dist;

void dijkstra(int start){
  dist[start] = 0;
  priority_queue<pair<long long, pair<int, int>>> PQ; // dist, <node, max>
  PQ.push({0, {start, 0}});

  while(!PQ.empty()){
    long long w = -PQ.top().first;
    int v = PQ.top().second.first;
    int maxw = PQ.top().second.second;
 
    PQ.pop();

    if(w != dist[v])
      continue;

    for(auto x : G[v]){
      long long add;
      if(x.second > maxw){
        add = x.second/2 + maxw - maxw/2;
        maxw = x.second;
      } else{
        add = x.second;
      }
      if(dist[x.first] > dist[v] + add){
        dist[x.first] = dist[v] + add;
        PQ.push({-dist[x.first], {x.first, maxw}});
      }
    }
  }
}

int main(){ fastio;
  int m;
  cin >> n >> m;
  int start = 1; // starting node
  G.resize(n+1);
  dist.resize(n+1, INF);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    //G[b].push_back({a, w});
  }

  dijkstra(start);

  long long ans = dist[n];
  cout << ans;
}