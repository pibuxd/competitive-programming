#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> G;
vector<int> V;
int n, q;

void readTree(){
  for(int i = 1; i <= n; i++){
    cin >> V[i];
  }

  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
}

int main(){
  cin >> n >> q;
  V = vector<int>(n+1);
  G = vector<vector<int>>(n+1);

  readTree();
  
}