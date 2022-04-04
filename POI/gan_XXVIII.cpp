// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, z, W, st_pre, st_post;
vector<vector<array<int, 2>>> G;
vector<int> pre, post, dep;
vector<array<int, 2>> par, in;
unordered_map<int, vector<int>> M;
unordered_map<int, int> diffs;

void build(int v, int p, vector<int> &B, int dif){
  pre[v] = ++st_pre;

  for(auto node : G[v]){
    int x = node[0], c = node[1];    
    if(x == p) continue;
    
    dep[x] = dep[v] + 1;
    par[x] = {v, c};

    B[c]++;
    if(B[c] == 1) dif++;

    if(dep[x] % W == 0){
      M[x] = B;
      diffs[x] = dif;
    }
    build(x, v, B, dif);
    
    if(B[c] == 1) dif--;
    B[c]--;
  }

  post[v] = ++st_post;
}

int query(int v, vector<int> &B, vector<int> &dif, int s_d){
  int x = par[v][0], c = par[v][1];
  if(x == -1){
    return s_d;
  }

  B[c]++;
  if(B[c] == 1) dif.push_back(c), s_d++;

  if(dep[x] % W == 0){
    int licz = diffs[x];
    for(int d : dif){
      if(M[x][d] == 0) licz++;
    }
    return licz;
  }

  return query(x, B, dif, s_d);
}

void update(int it, int val){
  array<int, 2> edge = in[it];
  if(edge[1] == par[edge[0]][0])
    swap(edge[0], edge[1]); // first is parent of second

  for(auto &i : M){
    if(pre[i.first] >= pre[edge[1]] && post[i.first] <= post[edge[1]]){
      M[i.first][par[edge[1]][1]]--;
      if(M[i.first][par[edge[1]][1]] == 0) diffs[i.first]--;

      M[i.first][val]++;
      if(M[i.first][val] == 1) diffs[i.first]++;
    }
  }

  par[edge[1]][1] = val;
}

int main(){
  fastio;
  cin >> n >> m >> z;
  W = 316;
  in.resize(n+1);
  G.resize(n+1);
  dep.resize(n+1);
  par.resize(n+1);
  pre.resize(n+1);
  post.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
    in[i] = {a, b};
  }

  dep[1] = 1;
  st_pre = st_post = 0;
  vector<int> temp0(m+1);
  build(1, 0, temp0, 0);
  par[1][0] = -1;

  while(z--){
    char op;
    int x;
    cin >> op >> x;
    if(op == 'Z'){
      vector<int> temp1(m+1), temp2;
      cout << query(x, temp1, temp2, 0) << "\n";
    }
    else{
      int c;
      cin >> c;
      update(x, c);
    }
  } 
}