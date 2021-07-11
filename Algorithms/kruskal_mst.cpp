// * Kruskal algorithm on MST (Minimum Spanning Tree)
// * using DSU (Disjoint Set Union)
// * detect if can't build MST
#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int a, b, w;

  bool operator<(const Edge &other){
    return w < other.w;
  }
};

int n, m, count_of_edges_in_mst;
long long weight_of_mst;
vector<Edge> edges; 
vector<int> parent;

void make_set(int v){
  parent[v] = v;
}

int find_set(int v){
  if(v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b)
    parent[b] = a;
}

void kruskal(){
  for(int i = 1; i <= n; i++)
    make_set(i);
  
  sort(edges.begin(), edges.end());
  for(Edge e : edges){
    int seta = find_set(e.a);
    int setb = find_set(e.b);

    if(seta != setb){
      union_sets(seta, setb);
      weight_of_mst += e.w;
      count_of_edges_in_mst++;
    }
  }
}

int main(){
  cin >> n >> m;
  edges.resize(m);
  parent.resize(n+1);

  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    edges[i] = {a, b, w};
  }

  weight_of_mst = count_of_edges_in_mst = 0;
  kruskal();

  if(count_of_edges_in_mst == n-1)
    cout << weight_of_mst;
  else
    cout << "IMPOSSIBLE";
}