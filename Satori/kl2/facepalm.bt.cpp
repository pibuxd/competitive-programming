// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int V, E;
vector<vector<int>> G;
vector<bool> visited, checked, were;
vector<int> dist, MEIN;

void initGraph(){
  cin >> V >> E;

  were.clear();
  visited.clear();
  checked.clear();
  dist.clear();
  G.clear();
  MEIN.clear();

  were.resize(V+1);
  visited.resize(V+1);
  checked.resize(V+1);
  dist.resize(V+1);
  G.resize(V+1);
}

void readGraph(){
  for(int i = 0; i < E; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void addFriends(int me){ //DFS
  vector<bool> been;
  been.resize(V+1);

  been[me] = true;
  for(int x : G[me])
    if(!been[x]){
      MEIN.push_back(x);
      addFriends(x);
    }
}

void distFindBFS(int start){
  visited[start] = true;
  queue<int> Q;

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();

    for(int x : G[n]){
      if(!visited[x]){
        visited[x] = true;
        dist[x] = dist[n] + 1;
        Q.push(x);
      }
    }
  }
}

void DFS(int n){
  were[n] = true;
  for(int x : G[n])
    if(!were[x]){
      DFS(x);
    }
}

int countTrees(){
  int ans = 0;
  for(int i = 1; i <= V; i++){
    if(!were[i]){
      DFS(i);
      ans++;
    }
  }
  return ans;
}

void printGraph(){
	for(int i = 1; i <= V; i++){
  	cout << i << ":";
  	for(int x : G[i])
    	cout << " " << x;
		cout << '\n';
	}
}

int main(){ //fastio
  int t; cin >> t;

  while(t--){
    initGraph();

    readGraph();
    int me; cin >> me;

    //printGraph();
    addFriends(me);

    //for(int x : G[me])
    //  MEIN.push_back(x);

    G[me].clear();

    for(int x : MEIN)
      G[me].push_back(x);

    printGraph();

    cout << "Znajomi numeru " << me << ":\n";

    distFindBFS(me);

    for(int i = 0; i < G[me].size(); i++){
      cout << G[me][i] << ": " << dist[i] + 1 << '\n';
    }

    cout << "Grup znajomych jest " << countTrees() << ".\n";
  }

  return 0;
}
