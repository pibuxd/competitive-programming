// turbo matching
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, nr;
vector<vector<char>> a;
vector<vector<int>> idx, G;
vector<int> vis, mt;

bool skok(int i, int j){
  return (1 <= i && i <= n && 1 <= j && j <= m && a[i][j] == '.');
}

bool match(int v){
  if(vis[v] == nr)
    return false;
  vis[v] = nr;

  for(int x : G[v])
    if(!mt[x]){
      mt[x] = v;
      return true;
    }
  for(int x : G[v])
    if(match(mt[x])){
      mt[x] = v;
      return true;
    } 

  return false;
}

int main(){
  fastio;
  cin >> n >> m;

  a.resize(n+1, vector<char>(m+1));
  mt.resize(n*m+1);
  idx.resize(n+1, vector<int>(m+1));
  G.resize(n*m+1);
  vis.resize(n*m+1);

  int id = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
      id++;
      idx[i][j] = id;
    }
  }
  
  int wolnepola = 0;
  vector<int> off({-1, -2, 1, 2});

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i][j] == '#') continue;
      wolnepola++;
    
      for(int oi : off){
        for(int oj : off){
          if(abs(oi) + abs(oj) != 3)
            continue;
          if(skok(i+oi, j+oj)){
            G[idx[i+oi][j+oj]].push_back(idx[i][j]);
            G[idx[i][j]].push_back(idx[i+oi][j+oj]);
          }
        }
      }
    }
  }

  nr = 0;
  for(int i = 1; i <= n*m; i++){
    nr++;
    match(i);
  }

  int sum = 0;
  for(int i = 1; i <= n*m; i++){
    if(mt[i]){
      sum++;
    }
  }

  cout << wolnepola-(sum/2) << "\n";
}