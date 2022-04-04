// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;
 
const int MXN = 2e5;
vector<vector<int>> G(MXN+1);
int n, maximum;
int dist[MXN+1];


void readG(){
   for(int i = 1, a, b; i < n; i++){
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
}

void bfs(int x){
   queue<int> Q;
   vector<bool> visited(MXN+1);
   visited[x] = true;
   Q.push(x);
   dist[x] = 0;
   int v;

   while(!Q.empty()){
      v = Q.front();
      Q.pop();

      for(int u : G[v]){
         if(!visited[u]){
            Q.push(u);
            visited[u] = true;
            dist[u] = dist[v] + 1;
            maximum = u;
         }
      }
   }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   cin >> n;
   readG();
   bfs(1);
   bfs(maximum);
   cout << dist[maximum];
} 