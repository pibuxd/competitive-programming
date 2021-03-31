#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, x, y;
vector<vector<int>> tab, wzor;
vector<vector<bool>> visited;

bool go(int a, int b){
  if(a >= 1 && a <= m && b >= 1 && b <= n && !visited[a][b]){
    return true;
  }
}

void dfs(int a, int b){
  visited[a][b] = true;

  if(go(a))
}

int main(){
  fastio;
  cin >> n >> m >> x >> y;

  tab.resize(m+1, vector<int>(n+1));
  visited.resize(m+1, vector<bool>(n+1));
  wzor.resize(y+1, vector<int>(x+1));

  for(int i = 1, t; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> tab[i][j];
    }
  }

  wzor.resize(y+1, vector<int>(x+1));
  for(int i = 1, t; i <= y; i++){
    for(int j = 1; j <= x; j++){
      cin >> wzor[i][j];
    }
  }

  for(int i = 1, t; i <= m; i++){
    for(int j = 1; j <= n; j++){
      if(!visited[i][j]){
        dfs(i, j);
      }
    }
  }
}