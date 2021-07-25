// * DSU
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> p, parent;
vector<array<int, 3>> edges;

void make_set(int v){
  parent[v] = v;
}

int find_set(int v){
  if(parent[v] == v)
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b)
    parent[b] = a;
}

int main(){
  ifstream in; ofstream out; in.open("wormsort.in"); out.open("wormsort.out");
  
  in >> n >> m;
  p.resize(n+2);
  parent.resize(n+1);
  edges.resize(m);

  for(int i = 1; i <= n+1; i++)
    make_set(i);

  for(int i = 1; i <= n; i++){
    in >> p[i];
    if(p[i] == i)
      union_sets(i, n+1);
  }
  
  for(auto &e : edges)
    in >> e[1] >> e[2] >> e[0];
  
  sort(edges.begin(), edges.end(), greater<array<int, 3>>());
  int mine = INT_MAX;

  for(auto &e : edges){
    int a = find_set(e[1]);
    int b = find_set(e[2]);
    if(a != b){
      union_sets(e[1], e[2]);
      mine = min(mine, e[0]);
    }
  }
  
  if(mine == INT_MAX)
    mine = -1;
  out << mine << "\n";
}