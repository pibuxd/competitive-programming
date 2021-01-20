#include "bits/stdc++.h"
using namespace std;
 
const int MXN = 2e5;
vector<vector<int>> G(MXN+1);
vector<int> cont(MXN+1);
vector<vector
int n, m;

void readG(){
   for(int i = 1, a, b; i < n; i++){
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
}
 
void BFS(int s, int e){
   int parent[MXN+1];
   vector<bool> visited(MXN+1);
   visited[s] = true;
   queue<int> Q;
   Q.push(s);
 
   while(!Q.empty()){
      int n = Q.front();
      Q.pop();

      for(int x : G[n]){
         if(!visited[x]){
            visited[x] = true;
            Q.push(x);
            parent[x] = n;
            if(x == e)
               goto sum;
         }
      }
   }

sum:
   while(e != s){
      cont[e]++;
      e = parent[e];
   }
   cont[s]++;
}
 
void Path(int a, int b){
   BFS(a, b);
}

int main(){
   cin >> n >> m;
   readG();
   for(int i = 0, a, b; i < m; i++){
      cin >> a >> b;
      Path(a, b);
   }

   for(int i = 1; i <= n; i++){
      cout << cont[i] << ' ';
   }
}