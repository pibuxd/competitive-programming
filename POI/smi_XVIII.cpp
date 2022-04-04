// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int lszkyz, lulic; cin >> lszkyz >> lulic;

  vector<vector<int>> G;
  vector<vector<int>> czyste;
  vector<vector<int>> brudne;
  G.resize(lulic+1);
  czyste.resize(lulic+1);
  brudne.resize(lulic+1);

  for(int i = 1; i <= lulic; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);

    int s, t; cin >> s >> t;
    if(s == 0){
      czyste[a].push_back(b);
      czyste[b].push_back(a);
    } else{
      brudne[a].push_back(b);
      brudne[b].push_back(a);
    }
  }
}
