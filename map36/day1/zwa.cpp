#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct vertex {
  int x, y;
};

int n, m;
vector<vector<char>> tab;

bool e(int a, int b){
  return (a >= 1 && a <= n && b >= 1 && b <= m && tab[a][b] != 'X');
}

int bfs(deque<pair<vertex, int>> &dq, vector<vector<int>> &D){
  int mn = INT_MAX;

  while(!dq.empty()){
    vertex v = dq.front().first;
    int dist = dq.front().second;
    dq.pop_front();

    if(v.x == n || v.y == 1){
      mn = min(mn, dist);
    } else{
      for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
          if(i == j) continue; // aby nie isc na ukos

          int X = v.x + i, Y = v.y + j;
          if(e(X, Y) && D[X][Y] > dist + (tab[X][Y] == '.')){
            D[X][Y] = dist + (tab[X][Y] == '.');
            if(tab[X][Y] == 'O')
              dq.push_front({{X, Y}, dist});
            else if(tab[X][Y] == '.')
              dq.push_back({{X, Y}, dist + 1});
          }
        }
      }
    }
  }

  return mn;
}

int main(){
  fastio;
  cin >> n >> m;

  tab.assign(n+1, vector<char>(m+1, ' '));

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> tab[i][j];
  
  deque<pair<vertex, int>> dq;
  vector<vector<int>> D(n+1, vector<int>(m+1, INT_MAX));
  
  // gora - dol, gora - lewo
  for(int i = 1; i <= m; i++){
    D[1][i] = (tab[1][i] == '.');
    if(tab[1][i] == 'O') dq.push_front({{1, i}, 0});
    else if(tab[1][i] == '.') dq.push_back({{1, i}, 1});
  }
  int mn = bfs(dq, D);

  dq.clear();
  D.assign(n+1, vector<int>(m+1, INT_MAX));
  // prawo - lewo, prawo - dol
  for(int i = 1; i <= n; i++){
    D[i][m] = (tab[i][m] == '.');
    if(tab[i][m] == 'O') dq.push_front({{i, m}, 0});
    else if(tab[i][m] == '.') dq.push_back({{i, m}, 1});
  }

  mn = min(mn, bfs(dq, D));

  cout << (mn == INT_MAX ? -1 : mn) << "\n";
}