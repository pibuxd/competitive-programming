// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;

    int V[n], SORTED[n];

    for(int i = 0; i < n; i++){
      cin >> V[i];
      SORTED[i] = V[i];
    }

    sort(SORTED, SORTED + n);
    int sum = 0;

    for(int i = 0; i < n; i++){
      if(SORTED[i-sum] != V[i])
        sum++;

    }

    cout << sum << '\n';
  }
}
