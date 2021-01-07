#include "bits/stdc++.h"
using namespace std;
 
const int MXN = 2e5;
vector<vector<int>> G(MXN+1);
int n, maximum = 0;

void readG(){
   for(int i = 1, a, b; i < n; i++){
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
   }
}
 
void BFS(int start){
   int last = start;
   vector<int> di(MXN+1);
   queue<int> Q;
   Q.push(start);
 
   while(!Q.empty()){
      int n = Q.front();
      Q.pop();
      last = n;

      for(int x : G[n]){
         Q.push(x);
         di[x] = di[n] + 1;
      }
   }

   if(di[last] > maximum){
      maximum = di[last];
   }   
}
 
void CreateStartPoints(vector<int> &starts){
   vector<bool> notLast(n+1);
 
   for(int i = 1; i <= n; i++){
      for(int x : G[i]){
         notLast[x] = true;
      }
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
      BFS(x);
   }
}
 
int main(){
   cin >> n;
 
   readG();
   PrintSubordinates();
   cout << maximum;
}