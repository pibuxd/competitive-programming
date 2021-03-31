#include "bits/stdc++.h"
using namespace std;
// Bellman Ford

const int INF = 1e9;
int V, KR, s, e;

void readG(vector<vector<pair<int, int>>> &G){
  for(int i = 0, a, b, d; i < KR; i++){
    cin >> a >> b >> d; // node a, node b, distance (weight)
    G[a].push_back({b, d});
  }
  cin >> s >> e; // start, end
}

void createE(vector<pair<int, int>> &E, vector<int> &weight, vector<vector<pair<int, int>>> &G, vector<bool> &confirm){
  queue<int> Q;
  vector<bool> visited(V+1);
  visited[s] = true;
  Q.push(s);
  vector<int> przed;
  vector<pair<int, int>> parent(V+1);

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();

    for(auto x : G[n]){
      if(!visited[x.first]){
        visited[x.first] = true;
        Q.push(x.first);
        parent[x.first] = {n, x.second};
      } else{
        E.push_back({n, x.first});
        weight.push_back({x.second});
      }
      if(x.first == e){
        E.push_back({n, x.first});
        weight.push_back(x.second);
        przed.push_back(n);
      }
    }
  }
  
  for(int x : przed){
    int n = x;
    while(n != s){
      E.push_back({parent[n].first, n});
      weight.push_back(parent[n].second);
      confirm[n] = true;
      confirm[parent[n].first] = true;
      n = parent[n].first;
    }
  }
}

void infoAbout(vector<vector<pair<int, int>>> &G){
  vector<pair<int, int>> E;
  vector<int> weight;
  vector<bool> confirm(V+1);
  createE(E, weight, G, confirm);

  vector<int> dist(V+1, INF);
  dist[s] = 0;

  for(int i = 1; i < V; i++)
    for(int i = 0; i < E.size(); i++)
      if(dist[E[i].first] + weight[i] < dist[E[i].second])
        dist[E[i].second] = dist[E[i].first] + weight[i];

  
  
  for(int i = 0; i < E.size(); i++)
    if(dist[E[i].first] + weight[i] < dist[E[i].second] && confirm[E[i].first]){
      cout << "Luka w systemie bankowym!\n";
      return;
    }
   

  if(dist[e] == INF) // nie wiem czego tu musze odjac 2 od INF
    cout << "Bank niedostepny!\n";
  else if(dist[e] >= 0)
    cout << "Minimalny koszt: " << dist[e] << '\n';
  else
    cout << "Luka w systemie bankowym!\n";

}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while(T--){
    cin >> V >> KR;
    vector<vector<pair<int, int>>> G(V+1);
    readG(G);
    infoAbout(G);
  }
}
