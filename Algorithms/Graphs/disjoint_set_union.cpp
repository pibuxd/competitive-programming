// * Disjoint Set Union (DSU)
// siz - size of unions
// smaller union merge with bigger union
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> parent, siz;

void make_set(int v){
  parent[v] = v;
  siz[v] = 1;
}

int find_set(int v){
  if(parent[v] == v)
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b){
    if(siz[a] < siz[b])
      swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
  }
}

int main(){
  cin >> n >> m;
  parent.resize(n+1);
  siz.resize(n+1);

  for(int i = 1; i <= n; i++)
    make_set(i);
  
  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;

    a = find_set(a);
    b = find_set(b);
    if(a != b)
      union_sets(a, b);
  }
}