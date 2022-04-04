// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

const int MXN = 2e5;
vector<int> G(MXN+1);
vector<int> dist(MXN+1);
vector<bool> visited(MXN+1);
int n;

void readG(){
   for(int i = 2, a; i <= n; i++){
      cin >> a;
      G[i] = a;
   }
}

void DFS(int n, int dlg){
   if(!visited[n])
      dlg++;

   visited[n] = true;

   dist[G[n]] += dlg;
   if(n != 1)
      DFS(G[n], dlg);
}

void CreateStartPoints(vector<int> &starts){
   vector<bool> notLast(n+1);

   for(int i = 1; i <= n; i++){
      notLast[G[i]] = true;
   }

   for(int x = 1; x <= n; x++){
      if(!notLast[x]){
         starts.push_back(x);
      }
   }
}

void PrintSubordinates(){
   vector<int> starts;
   CreateStartPoints(starts);

   for(int x : starts){
      int dlg = 0;
      DFS(x, dlg);
   }

   for(int x = 1; x <= n; x++){
      cout << dist[x] << ' ';
   }
}

int main(){
   cin >> n;

   readG();
   PrintSubordinates();
}