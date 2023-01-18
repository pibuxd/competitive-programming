#include <bits/stdc++.h>
using namespace std;
#include "cliclib.h"

int n, stos, stawka, A, B, l = 15;
vector<vector<vector<int>>> V; // 1 - win, 2 - lose

void dfs(int x, int st, int a, int b){ // stos = x, stawka = st = 2^a * 3^b
  if(V[x][a][b] != 0)
    return;
  if(x + st >= n){
    V[x][a][b] = 2;
    return;
  }
  dfs(x, st*2, a+1, b);
  dfs(x, st*3, a, b+1);
  dfs(x+st, 1, 0, 0);
  
  if(V[x][a+1][b] == 1 && V[x][a][b+1] == 1 && V[x+st][0][0] == 1)
    V[x][a][b] = 2;
  else
    V[x][a][b] = 1;
}

int a(){
  if(V[stos][A+1][B] == 2){
    A++;
    stawka *= 2;
    return 2;
  }
  if(V[stos][A][B+1] == 2){
    B++;
    stawka *= 3;
    return 3;
  }
  
  stos += stawka, stawka = 1, A = 0, B = 0;
  return 1;
}

int main(){
  n = inicjuj();
  V.resize(n+1, vector<vector<int>>(l+1, vector<int>(l+1)));

  dfs(0, 1, 0, 0);
  stos = 0, stawka = 1, A = 0, B = 0;

  while(true){
    alojzy(a());

    int x = bajtazar();
    if(x == 1)
      stos += stawka, stawka = 1, A = 0, B = 0;
    else if(x == 2)
      stawka *= 2, A++;
    else
      stawka *= 3, B++;
  }
}
