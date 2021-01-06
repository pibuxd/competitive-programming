#include "bits/stdc++.h"
using namespace std;

void readGraph(vector<vector <pair<int, int>>> &G, int V){
  for(int i = 0; i < V-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(make_pair(b, 1));
    G[b].push_back(make_pair(a, 1));
  }
}

//BFS
void addDistant(vector<vector<pair<int, int>>> &G, int V, int start){
  vector<bool> visited(V+1);
  queue<int> Q;
  vector<int> dist(V+1);

  visited[start] = true;
  Q.push(start);

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();

    for(int x = 0; x < G[n].size(); x++){
      int f = G[n][x].first;
      if(!visited[f]){
        visited[f] = true;

        dist[f] = dist[n] + 1;
        if(dist[f] > 1)
          G[start].push_back(make_pair(f, dist[f]));

        Q.push(f);
      }
    }
  }
}

void printGraph(vector<vector<pair<int, int>>> G, int V){
  for(int i = 1; i <= V; i++){
    cout << '\n' << i << "==";
    for(int x = 0; x < G[i].size(); x++)
      cout << "  " << G[i][x].first << " " << G[i][x].second;
  }
  cout << '\n';
}

int hotels(vector<vector<pair<int, int>>> G, int V){
  int ans = 0;

  for(int i = 0; i < V; i++){
    vector<int> licz(V+1);

    for(int x = 0; x < G[i].size(); x++)
      licz[G[i][x].second]++;

    for(int i = 1; 0 < licz[i]; i++)
      ans += licz[i] / 3;
  }
  return ans;
}

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int V;  cin >> V;
  vector<vector <pair<int, int>>> G(V+1);
  readGraph(G, V);

  for(int i = 1; i <= V; i++)
    addDistant(G, V, i);

  printGraph(G, V);

  cout << "\n" << hotels(G, V) / 3;
}
