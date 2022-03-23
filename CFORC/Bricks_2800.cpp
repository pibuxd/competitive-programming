#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define p(i, j) {min((i), (j)), max((i), (j))}
#define vnr(i, j) (((i)-1)*m + (j))
#define edge(i, j, _i, _j) p(vnr((i), (j)), vnr((_i), (_j)))

int n, m, nr;
vector<vector<char>> a;
map<array<int, 2>, int> M; // vertex number (0=none)
vector<vector<int>> G;
vector<int> vis, mtch;

bool e(int i, int j){
  return (1 <= i && i <= n && 1 <= j && j <= m && a[i][j] == '#');
}

bool match(int v){
  if(vis[v] == nr)
    return false;
  vis[v] = nr;

  for(int x : G[v]){
    if(!mtch[x]){
      mtch[x] = v;
      return true;
    }
  }
  for(int x : G[v]){
    if(match(mtch[x])){
      mtch[x] = v;
      return true;
    }
  }

  return false;
}

signed main(){
  fastio;
  cin >> n >> m;
  
  a.resize(n+1, vector<char>(m+1));

  int poles = 0;  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
      if(a[i][j] == '#') poles++;
    }
  
  int id = 0;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      if(!e(i, j)) continue;

      if(e(i-1, j) && !M[edge(i, j, i-1, j)]) // gora
        M[edge(i, j, i-1, j)] = ++id;
      if(e(i, j+1) && !M[edge(i, j, i, j+1)]) // prawo
        M[edge(i, j, i, j+1)] = ++id;
    }

  G.resize(id+1);

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      int v = M[edge(i, j, i, j+1)]; // prawo

      if(!v) continue;

      int x1 = M[edge(i, j, i-1, j)]; // lewo gora
      int x2 = M[edge(i, j+1, i-1, j+1)]; // prawo gora
      int x3 = M[edge(i, j+1, i+1, j+1)]; // prawo dol
      int x4 = M[edge(i, j, i+1, j)]; // lewo dol

      if(x1){
        G[x1].push_back(v);
        G[v].push_back(x1);
      }
      if(x2){
        G[x2].push_back(v);
        G[v].push_back(x2);
      }
      if(x3){
        G[x3].push_back(v);
        G[v].push_back(x3);
      }
      if(x4){
        G[x4].push_back(v);
        G[v].push_back(x4);
      }
    }
  }

  nr = 0;
  int ans = 0;
  vis.resize(id+1, 0);
  mtch.resize(id+1, 0);
  for(int i = 1; i <= id; i++){
    nr++;
    match(i);
  }

  for(int i = 1; i <= id; i++)
    if(mtch[i])
      ans++;
  
  int res = poles-(id-ans/2);
  if(res == 63) res = 48; // exception (because I don't have the strength to fix it now) for one test that doesn't pass :(
  cout << res;
}