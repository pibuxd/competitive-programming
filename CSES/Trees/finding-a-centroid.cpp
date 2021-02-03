#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> G;
vector<int> ile;

int findCentroid(int x = 1){
  for(int v : G[x]){
    if(ile[v] > n / 2){
      ile[x] -= ile[v];
      ile[v] = n;
      return findCentroid(v);
    }
  }
  
  return x;
}

int main(){
  cin >> n;
  G = vector<vector<int>>(n+1);
  ile = vector<int>(n+1);

  for(int i = 1, a, b; i < n; i++){
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << findCentroid();
}