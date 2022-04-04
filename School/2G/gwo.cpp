// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int maxGwozdzie(map<int, int> M, int n, int k, int V[]){
  int maximum = 0;
  for(int i = 0; i < n; i++){
    i += M[V[i]] - 1;

    if(i + k <= n-1)
      maximum = max(maximum, M[V[i]] + k);
    else
      maximum = max(maximum, M[V[i]] + n - 1 - i);
  }

  return maximum;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, k;
  cin >> n >> k;

  map<int, int> M;
  int V[n];

  for(int i = 0; i < n; i++){
    cin >> V[i];

    if(!M[V[i]])
      M[V[i]] = 1;
    else
      M[V[i]]++;
  }

  sort(V, V+n);

  cout << maxGwozdzie(M, n, k, V);
}
