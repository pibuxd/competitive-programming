#include <bits/stdc++.h>
using namespace std;
//bfs (przeszukiwanie grafu wszerz)

int V, E; //ilosc wierzcholkow i krawedzi
vector<vector<int>> G; //graf
bitset<100000> visited;
vector<int> parent, dist;

void read_graph(){ //wczyta graf
	cin >> V >> E;
	parent.resize(V+1);
  dist.resize(V+1);
  G.resize(V+1);
  for(int i = 0; i < E; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

void print_graph(){
	for(int i = 1; i <= V; i++){
  	cout << i << ":";
  	for(int x : G[i])
    	cout << " " << x;
		cout << '\n';
	}
}

void BFS(int start){
  visited[start] = true;
  queue<int> Q;
  Q.push(start);
  while(!Q.empty()){ //dopóki kolejka nie jest pusta
    int n = Q.front();
    Q.pop();
    for(int x : G[n]){
      if(!visited[x]){
        visited[x] = true;
        parent[x] = n;
        dist[x] = dist[n] + 1;
        Q.push(x);
      }
    }
  }
}

int main(){
  read_graph();
	cout << '\n';
  print_graph();
  BFS(1);
  for(int i = 1; i <= V; i++)
    cout << i << ": parent=" << parent[i] << " dist=" << dist[i] << '\n';
}
