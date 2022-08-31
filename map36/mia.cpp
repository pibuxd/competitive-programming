#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, logn;
vector<vector<int>> up;
vector<int> depth;

int lca(int a, int b){
  if(depth[a] < depth[b])
    swap(a, b); // so depth[a] > depth[b]
  int k = depth[a] - depth[b];

  for(int i = 0; i <= logn; i++)
    if(k & (1 << i))
    // if((k >> i) & 1)
      a = up[a][i];
  
  if(a == b)
    return a;
  
  for(int i = logn; i >= 0; i--)
    if(up[a][i] != up[b][i])
      a = up[a][i], b = up[b][i];
  
  return up[a][0];
}

int dist(int a, int b){
  return depth[a] + depth[b] - 2*depth[lca(a, b)];
}

int main(){
  fastio;
  cin >> n;
  logn = ceil(log2(n));

  up.resize(n+1, vector<int>(logn+1));
  depth.resize(n+1);

  depth[0] = 1;
  int v1, v2, diam;
  v1 = v2 = diam = 0;

  for(int v = 1; v <= n; v++){
    int p; cin >> p;
    depth[v] = depth[p] + 1;

    up[v][0] = p;
    for(int i = 1; i <= logn; i++)
      up[v][i] = up[up[v][i-1]][i-1];

    int d1 = dist(v1, v), d2 = dist(v2, v);
    // cout << d1 << ", " << d2 << "\n";
    if(d1 > diam && d1 >= d2)
      v1 = v1, v2 = v, diam = d1;
    else if(d2 > diam && d2 >= d1)
      v1 = v2, v2 = v, diam = d2;

    cout << diam << "\n";
  }
}