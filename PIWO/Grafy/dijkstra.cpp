// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int UNKNOWN = -1;

int V, E;

struct vertex{
  bool ok;
  int nr, parent, price;
  vector<int> adj, weight;
};

bool operator < (const vertex &x, const vertex &y){
  return x.price > y.price;
}

vector<vertex> G;
priority_queue<vertex> Q;

void read_data(){
  cin >> V >> E;
  G.resize(V+1);
  for(int n = 1; n <= V; n++){
    G[n].price = INF;
    G[n].nr = n;
    G[n].parent = UNKNOWN;
    G[n].ok = false;
  }
  for(int i = 0; i < E; i++){
    int a, b, w;
    cin >> a >> b >> w;
    G[a].adj.push_back(b);
    G[b].adj.push_back(a);
    G[a].weight.push_back(w);
    G[b].weight.push_back(w);
  }
}

void dijkstra(){
  G[1].price = 0;
  for(int n=1; n<=V; n++)
    Q.push(G[n]);
  int i=1;
  while(i<=V){
    vertex x = Q.top(); Q.pop();
    if(G[x.nr].ok)
      continue;
    G[x.nr].ok = true;
    for(int j = 0; j < x.adj.size(); j++){
      int u = x.adj[j];
      int p = x.price + x.weight[j];
      if(p < G[u].price){
        G[u].parent = x.nr;
        G[u].price = p;
        Q.push(G[u]);
      }
    }
    i++;
  }
}

int main(){
  read_data();
  dijkstra();
  for(int n = 1; n <= V; n++)
    cout << n << " " << G[n].parent << " " << G[n].price << endl;
}
