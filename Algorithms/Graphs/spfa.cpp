// Shortest Path Faster Algorithm
// https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
// * finds shortest paths from a starting node to all nodes
// directed or undirected weighted graph, negative weight edges are ok

#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_MAX;
int n, m;
vector<vector<pair<int, long long>>> G;
vector<long long> dist;

void spfa(int start){
  dist[start] = 0;
  deque<int> dq;
  dq.push_back(start);

  while(!dq.empty()){
    int v = dq.front();
    dq.pop_front();

    for(auto x : G[v]){
      if(dist[x.first] != INF && dist[x.first] > dist[v] + x.second){
        dq.push_front(x.first);
        dist[x.first] = dist[v] + x.second;
      }
      else if(dist[x.first] == INF){
        dq.push_back(x.first);
        dist[x.first] = dist[v] + x.second;
      }
    }
  }
}

int main(){
  int start; // starting node
  cin >> n >> m;
  G.resize(n+1);
  dist.resize(n+1, INF);

  for(int i = 1; i <= m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    //G[b].push_back({a, w});
  }

  spfa(start);
  for(int i = 1; i <= n; i++)
    cout << dist[i] << " ";
}