// * finds all shortest paths between the nodes in a single run.
// directed or an undirected weighted graph, no negative weight cycles
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<vector<pair<int, int>>> G;
vector<vector<int>> dist, parent;

vector<int> shortest_path(int a, int b){
  vector<int> path;
  if(!parent[a][b])
    return path;

  path.push_back(a);
  while(a != b){
    a = parent[a][b];
    path.push_back(a);
  }

  return path;
}

void floyd_warshall(){
  for(int i = 1; i <= n; i++)
    dist[i][i] = 0, parent[i][i] = i;
  
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++){
        if(dist[i][j] > dist[i][k] + dist[k][j]){
          dist[i][j] = dist[i][k] + dist[k][j];
          parent[i][j] = parent[i][k];
        }
      }
}

int main(){
  cin >> n >> m;
  dist.resize(n+1, vector<int>(n+1, INF));
  parent.resize(n+1, vector<int>(n+1));
  G.resize(n+1);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back({b, w});
    G[b].push_back({a, w});
    dist[a][b] = dist[b][a] = w;
    parent[a][b] = b;
    parent[b][a] = a;
  }

  floyd_warshall();
}