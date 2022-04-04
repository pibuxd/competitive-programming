// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long LOGN;
vector<long long> depth, w;
vector<vector<long long>> up, childs, G;

void __dfs(long long v, long long p){
  for(auto x : G[v]){
    if(x == p) continue;
    up[x][0] = v;
    childs[v].push_back(x);
    __dfs(x, v);
  }
}

void dfs(long long v){ // calculating binary lifting
  for(long long x : childs[v]){
    depth[x] = depth[v] + 1;
    for(long long i = 1; i < LOGN; i++)
      up[x][i] = up[up[x][i-1]][i-1];

    dfs(x);
  }
}

long long lca(long long a, long long b){
  if(depth[a] < depth[b])
    swap(a, b); // depth[a] > depth[b]
  long long k = depth[a] - depth[b];

  for(long long i = 0; i < LOGN; i++)
    if((k >> i) & 1)
      a = up[a][i];

  if(a == b)
    return a;

  for(long long i = LOGN - 1; i >= 0; i--){
    if(up[a][i] != up[b][i]){
      a = up[a][i];
      b = up[b][i];
    }
  }

  return up[a][0];
}

void recolor(long long a, long long b, long long val){
  long long lc = lca(a, b);
  w[lc] += val;
  while(a != lc){
    w[a] += val;
    a = up[a][0];
  }
  while(b != lc){
    w[b] += val;
    b = up[b][0];
  }
}

bool check(long long a, long long b){
  vector<long long> weights;
  long long lc = lca(a, b), w_size = 1;
  weights.push_back(w[lc]);

  while(a != lc){
    weights.push_back(w[a]);
    a = up[a][0];
    w_size++;
  }
  while(b != lc){
    weights.push_back(w[b]);
    b = up[b][0];
    w_size++;
  }

  for(long long x = 0; x < w_size; x++){
    for(long long y = 0; y < w_size; y++){
      for(long long z = 0; z < w_size; z++){
        if(x != y && x != z && y != z){
          if(weights[x] < weights[y] + weights[z] &&
             weights[y] < weights[x] + weights[z] &&
             weights[z] < weights[x] + weights[y]) return true;
        }
      }
    }
  }

  return false;
}

int main(){
  fastio;
  long long n;
  cin >> n;
  LOGN = ceil(log2(n)) + 1;
  
  depth = w = vector<long long>(n+1);
  childs = G = vector<vector<long long>>(n+1);
  up = vector<vector<long long>>(n+1, vector<long long>(LOGN));
  up[1][0] = 0;

  for(long long i = 1; i <= n; i++)
    cin >> w[i];

  for(long long i = 1; i <= n-1; i++){
    long long a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  __dfs(1, 0);
  dfs(1);
  
  long long q;
  cin >> q;

  while(q--){
    long long op, x, y;
    cin >> op;

    if(op == 2){
      long long a;
      cin >> x >> y >> a;
      recolor(x, y, a);
    }
    else{
      cin >> x >> y;
      long long lc = lca(x, y);
      long long dif = abs(depth[x] + depth[y] - 2*depth[lc]);
      if(dif > 200){
        cout << "Yes\n";
        goto jd;
      }
      if(check(x, y))
        cout << "Yes\n";
      else
        cout << "No\n";
      jd:;
    }
  }
}