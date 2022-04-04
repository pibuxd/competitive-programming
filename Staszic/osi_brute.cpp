// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, k, cnt;
vector<vector<array<bool, 4>>> blck;
vector<vector<bool>> vis;

int kr(int x, int y, int a, int b){
  if(y > b) return 0;
  if(x < a) return 1;
  if(y < b) return 2;
  if(x > a) return 3;
}

bool e(int a, int b, int x, int y){
  return (x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && !blck[a][b][kr(a, b, x, y)]);
}

void dfs(int x, int y){
  cnt++;
  vis[x][y] = true;

  if(e(x, y, x+1, y)){
    dfs(x+1, y);
  }
  if(e(x, y, x-1, y)){
    dfs(x-1, y);
  }
  if(e(x, y, x, y+1)){
    dfs(x, y+1);
  }
  if(e(x, y, x, y-1)){
    dfs(x, y-1);
  } 
}

int main(){
  fastio;
  cin >> n >> m >> k;

  blck.resize(n+1, vector<array<bool, 4>>(m+1, {false, false, false, false})); // gora, prawo, dol, lewo
  
  while(k--){
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    
    blck[x][y][kr(x, y, a, b)] = blck[a][b][kr(a, b, x, y)] = true;

    cnt = 0;
    vis.assign(n+1, vector<bool>(m+1, false));
    dfs(1, 1);

    if(cnt == n*m){
      cout << "TAK\n";

    } else{
      cout << "NIE\n";
      blck[x][y][kr(x, y, a, b)] = blck[a][b][kr(a, b, x, y)] = false;
    }
  }
}