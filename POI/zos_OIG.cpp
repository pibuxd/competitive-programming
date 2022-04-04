// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//global varriables
vector<bool> visited;
vector<int> urodziny;
vector<vector<int>> G;
vector<pair<int, int>> did;

int lgosci, mindzieci, V;


bool Done(int a, int b, vector<pair<int, int>> did){
  for(int i = 0; i < did.size(); i++){
    if(did[i].first == b && did[i].second == a)
      return true;
  }
  return false;
}

void readGraph(){
  for(int i = 1; i <= V; i++){
    int a, b; cin >> a >> b;
    if(!Done(a, b, did)){
      did.push_back(make_pair(a, b));
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
}

bool canJoin(int x){
  for(int i = 1; i <= G[x].size(); i++){
    for(int j = 0; j < urodziny.size(); j++){
      if(x == urodziny[j])
        return false;
    }
  }

  return true;
}

void DFS(int n){
  visited[n] = true;
  for(int i = 0; i < G[n].size(); i++){
    if(!visited[n]){
      if(canJoin(G[n][i]))
        urodziny.push_back(G[n][i]);
      DFS(G[n][i]);
    }
  }
}

void printGraph(){
  for(int i = 1; i <= lgosci; i++){
    cout << i << ' ';
    for(int j = 0; j < G[i].size(); j++){
      cout << G[i][j] << ' ';
    }
    cout << '\n';
  }
}

int main(){
  fastio
  cout << '\n';

  cin >> lgosci >> mindzieci >> V;

  G.resize(lgosci+1);
  visited.resize(1000000);

  readGraph();

  urodziny.push_back(1);

  for(int i = 1; i <= lgosci; i++){
    if(!visited[i]){
      DFS(i);
    }
  }

  int urodzinysize = urodziny.size();
  cout << urodzinysize << '\n';
  for(int i = 0; i < urodzinysize; i++)
    cout << urodziny[i] << ' ';

  return 0;
}
