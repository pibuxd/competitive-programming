#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> G;
vector<int> d1, d2; // dist do 1, do 2;

void bfs(int st, int en, vector<int> &d){
  vector<bool> vis(n+1);
  queue<int> q;

  d[st] = 0;
  vis[st] = true;
  q.push(st);
  
  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int x : G[v]){
      if(!vis[x]){
        vis[x] = true;
        if(x != en)
          q.push(x);

        d[x] = d[v] + 1;
      }
    }
  }
}

signed main(){
  cin >> n >> m;
  G.resize(n+1);
  d1.resize(n+1, -1);
  d2.resize(n+1, -1);

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs(1, 2, d1);
  bfs(2, 1, d2);

  
  // for(int i = 1; i <= n; i++){
  //   cout << d1[i] << ", " << d2[i] << "\n";
  // }

  int ans = 0;

  for(int i = 1; i <= n; i++){
    for(int j = i+1; j <= n; j++){
      if(i == j) continue;
      if(d1[i] == -1 && d2[i] == -1 && d1[j] == -1 && d2[j] == -1){ // oba poza 1 i 2
        d1[i] = d2[i] = d1[j] = d2[j] = -1;
      } else if(d1[i] == -1 && d2[i] == -1 && d1[j] == -1 && d2[j] != -1){ // i poza, j do 2
        d2[i] = d2[j] + 1;
      } else if(d1[i] == -1 && d2[i] == -1 && d2[j] == -1 && d1[j] != -1){ // i poza, j do 1
        d1[i] = d1[j] + 1;
      } else if(d1[j] == -1 && d2[j] == -1 && d1[i] == -1 && d2[i] != -1){ // i do 2, j poza
        d2[j] = d2[i] + 1;
      } else if(d1[j] == -1 && d2[j] == -1 && d2[i] == -1 && d1[i] != -1){ // i do 1, j poza
        d1[j] = d1[i] + 1;
      }
      else if(d1[i] == -1 && d2[i] == -1 && d1[j] != -1 && d2[j] != -1){ // i poza, j pomiedzy
        d1[i] = d1[j] + 1, d2[i] = d2[j] + 1;
      } else if(d1[i] != -1 && d2[i] != -1 && d1[j] == -1 && d2[j] == -1){ // i pomiedzy, j poza
        d1[j] = d1[i] + 1, d2[j] = d2[i] + 1;
      }
      else if(d1[i] != -1 && d2[i] != -1 && d1[j] == -1 && d2[j] != -1){ // i pomiedzy, j do 2
        int mnd = min(d2[j] + d1[i] + 1, d2[i] + d1[i]);
        if(mnd >= 5){
          d1[j] = d1[i] + 1;
          d2[i] = min(d2[i], d2[j] + 1);
        } 
        else ans--;

      } else if(d1[i] != -1 && d2[i] != -1 && d2[j] == -1 && d1[j] != -1){ // i pomiedzy, j do 1
        int mnd = min(d1[j] + d2[i] + 1, d1[i] + d2[i]);
        if(mnd >= 5){
          d2[j] = d2[i] + 1;
          d1[i] = min(d1[i], d1[j] + 1);
        } 
        else ans--;

      } else if(d1[i] == -1 && d2[i] != -1 && d1[j] != -1 && d2[j] != -1){ // i do 2, j pomiedzy
        int mnd = min(d2[i] + d1[j] + 1, d2[i] + d1[j]);
        if(mnd >= 5){
          d1[i] = d1[j] + 1;
          d2[j] = min(d2[i], d2[i] + 1);
        } 
        else ans--;

      } else if(d1[i] != -1 && d2[i] == -1 && d1[j] != -1 && d2[j] != -1){ // i do 1, j pomiedzy
        int mnd = min(d1[i] + d2[j] + 1, d1[j] + d2[j]);
        if(mnd >= 5){
          d2[i] = d2[j] + 1;
          d1[j] = min(d1[j], d1[i] + 1);
        } 
        else ans--;
      }
      else if(d1[i] == -1 && d1[j] == -1){ // oba do 2
        d2[i] = min(d2[i], d2[j]+1);
        d2[j] = min(d2[j], d2[i]+1);

      } else if(d2[i] == -1 && d2[j] == -1){ // oba do 1
        d1[i] = min(d1[i], d1[j]+1);
        d1[j] = min(d1[j], d1[i]+1);

      } else if(d1[i] == -1 && d2[j] == -1){ // i do 2, j do 1
        int mnd = d2[i] + d1[j] + 1;
        if(mnd >= 5){
          d1[i] = d1[j] + 1;
          d2[j] = d2[i] + 1;
        } else ans--;
      } else if(d2[i] == -1 && d1[j] == -1){ // i do 1, j do 2
        int mnd = d1[i] + d2[j] + 1;
        if(mnd >= 5){
          d2[i] = d2[j] + 1;
          d1[j] = d1[i] + 1;
        } else ans--;
      } else{ // oba pomiedzy
        int mnd = min({d1[i] + d2[j] + 1, d1[j] + d2[i] + 1, d1[i] + d2[i], d1[j] + d2[j]});
        if(mnd >= 5){
          d1[i] = min(d1[i], d1[j]+1);
          d2[i] = min(d2[i], d2[j]+1);
          d1[j] = min(d1[j], d1[i]+1);
          d2[j] = min(d2[j], d2[i]+1);
        } else ans--;
      }

      ans++;
    }
  }

  cout << ans - m;
}