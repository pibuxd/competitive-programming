// * Disjoint Set Union
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, sets, max_set;
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
    max_set = max(max_set, siz[a]);
  }
}

int main(){
  fastio;
  cin >> n >> m;
  parent.resize(n+1);
  siz.resize(n+1);
  sets = n;
  max_set = 0;

  for(int i = 1; i <= n; i++)
    make_set(i);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    a = find_set(a);
    b = find_set(b);
    if(a != b){
      sets--;
      union_sets(a, b);
    }
    cout << sets << " " << max_set << "\n";
  }
}
