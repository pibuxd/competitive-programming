#include <bits/stdc++.h>
using namespace std;

int n, czapka;
bool can_set;
vector<vector<int>> G;
vector<int> nr;
vector<bool> visited;

void initG(){
  G.resize(n+1);
}

bool compare(int a, int b){
  int a_size = G[a].size();
  int b_size = G[b].size();

  if(a_size < b_size && a > 2){
    return true;
  } else{
    return false;
  }
}

void push(int a, int b){
  G[a].push_back(b);
  G[b].push_back(a);
}

void bfs(int start){
  queue<int> Q;
  Q.push(start);
  visited[start] = true;

  while(!Q.empty()){
    int x = Q.front();
    Q.pop();

    for(int v : G[x]){
      if(!visited[v]){
        visited[v] = true;
        Q.push(v);
        nr[v] = czapka;
        czapka++;
      }
    }
  }
}

void generate(){
  for(int i = 1; i <= n; i++){
    sort(G[i].begin(), G[i].end(), compare);
  }

  visited.resize(n+1);
  nr.resize(n+1);
  czapka = 1;
  can_set = true;
  
  for(int i = 1; i <= n; i++){
    if(!visited[i]){
      nr[i] = czapka;
      czapka++;
      bfs(i);
    }
  }

}

void print(){
  if(!can_set){
    cout << "NIE";
    return;
  }
  
  cout << "TAK\n";

  for(int i = 1; i <= n; i++){
    cout << nr[i] << ' ';
  }
}

int main(){
  int m;
  cin >> n >> m;

  initG();

  for(int a, b; m--;){
    cin >> a >> b;
    push(a, b);
  }

  generate();
  print();
}