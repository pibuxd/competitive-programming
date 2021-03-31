#include "bits/stdc++.h"
using namespace std;

const int MXN = 1e3;
int n, m, si, sj, ei, ej;
char T[MXN][MXN];

bool e(int i, int j){
  return i >= 0 && i < n && j >= 0 && j < m && T[i][j] == '.';
}

void readT(){
  char a;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
      cin >> a;
      if(a == 'A'){
        si = i; sj = j;
        T[i][j] = '.';
      } else
        T[i][j] = a;
    }
}

void printPath(){ // BFS
  queue<pair<int, int>> Q;
  Q.push({si, sj});
  T[si][sj] = '#';
  vector<vector<pair<int, int>>> parent(MXN, vector<pair<int, int>>(MXN));

  while(!Q.empty()){
    pair<int ,int> v = Q.front();
    Q.pop();
    
    if(e(v.first+1, v.second)){   
      T[v.first+1][v.second] = '#'; 
      parent[v.first+1][v.second] = v; 
      Q.push({v.first+1, v.second});
    }   
    if(e(v.first-1, v.second)){     
      T[v.first-1][v.second] = '#'; 
      parent[v.first-1][v.second] = v; 
      Q.push({v.first-1, v.second});
    }   
    if(e(v.first, v.second+1)){   
      T[v.first][v.second+1] = '#'; 
      parent[v.first][v.second+1] = v; 
      Q.push({v.first, v.second+1});
    }   
    if(e(v.first, v.second-1)){    
      T[v.first][v.second-1] = '#'; 
      parent[v.first][v.second-1] = v; 
      Q.push({v.first, v.second-1});
    }
  
    if(v.first == 0 || v.first == n-1 || v.second == 0 || v.second == n-1){
      ei = v.first; ej = v.second;
      goto yes;
    }
  }
  cout << "NO";
  return;

yes:
  cout << "YES" << '\n';

  string droga = "";
  int a = ei, b = ej;
  
  if(ei == 0)
    droga += 'L';
  else if(ei == n-1)
    droga += 'D';
  else if(ej == 0)
    droga += 'U';
  else if(ej == n-1)
    droga += 'R';

  while(a != si || b != sj){
    if(parent[a][b].first == a && parent[a][b].second == b-1){
      b--;
      droga += 'R';
    } else if(parent[a][b].first == a && parent[a][b].second == b+1){
      b++;
      droga += 'L';
    } else if(parent[a][b].first == a-1 && parent[a][b].second == b){
      a--;
      droga += 'D';
    } else{
      a++;
      droga += 'U';
    }
  }

  cout << droga.size() << '\n';
  for(int i = droga.size() - 1; i >= 0; i--)
    cout << droga[i];
  

}

int main(){
  cin >> n >> m;
  readT();
  printPath();
}
