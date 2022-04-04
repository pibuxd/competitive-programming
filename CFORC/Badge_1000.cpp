// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;

  int P[n+1];
  for(int i = 1; i <= n; i++){
    cin >> P[i];
  }

  for(int i = 1; i <= n; i++){
    vector<bool> visited;
    visited.resize(n+1);
    int it = i;
    while(!visited[it]){
      visited[it] = true;
      it = P[it];
    }

    cout << it << ' ';
  }
}
