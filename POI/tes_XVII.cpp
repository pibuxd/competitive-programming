// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, p, l, g; cin >> g; vector<int> N, V;
  for(int i = 0; i < g; i++){
    cin >> p; N.push_back(p);
  } cin >> n;
for(int it = 0, s = 0, z = 0; it < n; it++, s = 0, z = 0){ cin >> l; V.clear();
  for(int i = 0; i < g; i++){
    if(i == l) z++;
    if(z == 0) { cin >> p; V.push_back(p); }
    if(V[s] == N[i]) s++;
    if(s < l && i == g - 1 && V[l] != N[g]) goto koniec;
  }
  cout << "TAK" << '\n';
  goto end;
  koniec:
  cout << "NIE" << '\n';
  end:;
}
}
