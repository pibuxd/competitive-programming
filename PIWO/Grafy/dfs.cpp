// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
//dfs (przeszukiwanie grafu wglab)

int V, E;
vector<vector<int>> G;
vector<bool> visited;
vector<int> parent, start, finish;
int t = 0;

void read_graph(){
	cin >> V >> E;
	visited.resize(V+1);
	start.resize(V+1);
	finish.resize(V+1);
	G.resize(V+1);
	parent.resize(V+1);

	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
    G[b].push_back(a);
	}
}

void dfs_visit(int n){
	visited[n] = true;
	start[n] = ++t;
	for(int x : G[n])
		if(!visited[x]){
			parent[x] = n;
			dfs_visit(x);
		}
	finish[n] = ++t;
}

int main(){
	read_graph();
	for(int i = 1; i <= V; i++)
		if(!visited[i])
			dfs_visit(i);
	for(int i = 1; i <= V; i++)
			cout << i << ": parent=" << parent[i] << " start=" << start[i] << " finish=" << finish[i] << '\n';
}
