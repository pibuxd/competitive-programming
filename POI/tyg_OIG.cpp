// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, x = 0, sum = 0, min = 1000000001, it; cin >> n; int V[n], I[n];
  for(int i = 0; i < n; i++){
    cin >> V[i];
    if(V[i] < min){ min = V[i]; it = i + 1; }
  }
  sum += min * it; min = 1000000001; x = it;
  while(it < n){
    for(int i = it; i < n; i++){
      if(V[i] < min){ min = V[i]; it = i + 1; }
    } sum += min * (it - x); x = it;
  }
  cout << sum;
}
