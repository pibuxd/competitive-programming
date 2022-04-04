// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m, si, sj, ei, ej;
string s[mxN];

bool e(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}

void bfs(){
  queue<pair<int, int>> Q;
  Q.push({si, sj});
  
  vector<vector<pair<int, int>>> parent(mxN, vector<pair<int, int>>(mxN));
  parent[si][sj] = {0, 0};
  
  while(!Q.empty()){
    pair<int, int> n = Q.front();   
    Q.pop();

    if(e(n.first+1, n.second)){   
      s[n.first+1][n.second] = '#'; 
      parent[n.first+1][n.second] = n;
      Q.push({n.first+1, n.second});
    }   
    if(e(n.first-1, n.second)){     
      s[n.first-1][n.second] = '#'; 
      parent[n.first-1][n.second] = n;
      Q.push({n.first-1, n.second});
    }   
    if(e(n.first, n.second+1)){   
      s[n.first][n.second+1] = '#'; 
      parent[n.first][n.second+1] = n;
      Q.push({n.first, n.second+1});
    }   
    if(e(n.first, n.second-1)){    
      s[n.first][n.second-1] = '#'; 
      parent[n.first][n.second-1] = n;
      Q.push({n.first, n.second-1});
    }
   
    if(n.first == ei && n.second == ej)
      goto yes;
    }
  cout << "NO";
  return;

yes:
  cout << "YES" << '\n';

  int a = ei, b = ej;
  string droga = "";

  while(a != si || b != sj){
    if(parent[a][b].first == a && parent[a][b].second == b-1){
      b--;
      droga += 'R';
    } else if(parent[a][b].first == a && parent[a][b].second == b+1){
      b++;
      droga += 'L';
    } else if(parent[a][b].first == a-1 &&  parent[a][b].second == b){
      a--;
      droga += 'D';
    } else{
      a++;
      droga += 'U';
    }
  }
  
  cout << droga.size() << '\n';
  for(int i = droga.size() - 1; i >= 0; i--){
    cout << droga[i];
  }
}

int main(){
  cin >> n >> m;
  
  for(int i = 0; i < n; i++){
    cin >> s[i];

    for(int j = 0; j < m; j++){
      if(s[i][j] == 'A')
        si = i, sj = j, s[i][j] = '.';
      else if(s[i][j] == 'B')
        ei = i, ej = j, s[i][j] = '.';
    } 
  }
   
  bfs();
}
