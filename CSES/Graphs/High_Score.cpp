// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int MXN = 2500;
int V, E;
vector<vector<pair<int, int>>> G(MXN+1);
vector<ll> targetDist;

void readG(){
  cin >> V >> E;
  for(int i = 0, a, b, c; i < E; i++){
    cin >> a >> b >> c;
    G[a].push_back({b, c});
  }
}

void findMax(){
  vector<bool> visited(MXN+1);
  vector<ll> dist(MXN+1);
  queue<int> Q;
  visited[1] = true;
  dist[1] = 0;
  Q.push(1);

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();

    for(auto v : G[n]){
      if(!visited[v.first]){
        visited[v.first] = true;
        Q.push(v.first);
        dist[v.first] = dist[n] + v.second;
        if(v.first == V){
          targetDist.push_back(dist[V]);
          visited[V] = false;
        }
      } 
    }
  }

  if(targetDist.empty())
    cout << "-1";
  else
    cout << *max_element(targetDist.begin(), targetDist.end());
}

int main(){
  readG();
  findMax();
}
