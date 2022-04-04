// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int z, Z[100000], t, sum_pref[100001], a, b, suma; cin >> t >> z;
  for(int i = 0; i < z; i++) cin >> Z[i];
  sum_pref[0] = 0;
  for(int i = 0; i < z; i++) sum_pref[i+1] = sum_pref[i] + Z[i];
  for(int i = 0; i < t; i++){
    cin >> a >> b;
    suma = sum_pref[b] - sum_pref[a-1];
    cout << suma << '\n';
  }
}
