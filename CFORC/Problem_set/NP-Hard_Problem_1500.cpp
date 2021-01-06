#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int V, E; cin >> V >> E;

  vector<vector<int>> G;
  G.resize(V+1);

  for(int i = 1; i <= V; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}
