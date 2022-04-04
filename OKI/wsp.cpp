// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;

int main(){
  fastio;
  cin >> n >> k;
  vector<int> occ(1<<k);

  for(int i = 1; i <= n; i++){
    bitset<13> bin;
    cin >> bin;
    occ[bin.to_ullong()]++;
  }

  unsigned long long res = 0;

  for(int i = 1; i < 1<<k; i++){
    res += ( occ[i] * (occ[i]-1) ) / 2;
    for(int j = i+1; j < 1<<k; j++){
      if(i != j && i & j)
        res += occ[i] * occ[j];
    }
  }

  cout << res;
}