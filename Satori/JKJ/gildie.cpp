// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

bool sizecom(const vector<int>& v1, const vector<int>& v2){
  return v1.size() < v2.size();
}

int main(){ //ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m; //liczba miast i drog

    vector<vector<int>> G;
    G.resize(n+1);

    for(int i = 1; i <= n; i++){ //tworzenie grafu
      G[i].push_back(i);
    }

    for(int i = 0; i < m; i++){ //lista sasiedztwa
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    sort(G.begin(), G.end(), sizecom);
    int IT[n+1];

    for(int i = 1; i <= n; i++){
      IT[G[i][0]] = i;
    }
    char gildia[n];

    gildia[0] = 'K';
    for(int i = )
    for(int i = 2; i <= n; i++){

    }
  }
}
