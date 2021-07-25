// * Disjoint Set Union (DSU)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<int> parent;

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
  return 0;
}