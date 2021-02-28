#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MOD = 1e9+7;
int n, m, sum, color, startx, starty, hashSum;
vector<vector<int>> tab;
set<int> hashes;
vector<vector<bool>> visited;
vector<int> potx, poty;

bool exists(int x, int y){
  if(x > n || y > m || x < 1 || y < 1){
    return false;
  }
  
  if(!visited[x][y] && tab[x][y] == color){
    return true;
  } else{
    return false;
  }
}

void dfs(int x, int y){
  visited[x][y] = true;
  
  int temp = abs(x-startx+1);
  hashSum += ((temp) * potx[temp]) % MOD;

  temp = abs(y-starty+1);
  hashSum += ((temp) * poty[temp]) % MOD;
  

  if(exists(x, y-1)){
    dfs(x, y-1);
  } else if(exists(x, y+1)){
    dfs(x, y+1);
  } else if(exists(x+1, y)){
    dfs(x+1, y);
  }
}

int main(){
  fastio;
  int t;
  cin >> t;

  potx.resize(1001);
  poty.resize(1001);
  potx[0] = poty[0] = 1;

  for(int i = 1; i <= 1000; i++){
    potx[i] = potx[i-1] * 29 % MOD;
    poty[i] = poty[i-1] * 31 % MOD;
  }


  while(t--){
    cin >> n >> m;
    tab.resize(n+1, vector<int>(m+1));
    visited.resize(n+1, vector<bool>(m+1));
    hashes.clear();

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        cin >> tab[i][j];
      }
    }

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= m; j++){
        if(!visited[i][j]){
          hashSum = 0;
          startx = i;
          starty = j;
          color = tab[i][j];
          dfs(i, j);
          hashes.insert(hashSum);
        }
      }
    }

    cout << hashes.size() << '\n';
  }
}