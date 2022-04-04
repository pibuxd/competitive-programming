// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int m, d, n, p, odl = 0, tax = 0; cin >> m >> d >> n; vector<int> v;
  for(int i = 0; i < n; i++){
    cin >> p; v.push_back(p);
  }
  sort(v.rbegin(), v.rend());
  for(int i = 0; m > odl; i++){
    if(d > odl)
      odl += (abs(v[i] - (d - odl)));
    else
      odl += (v[i] - (d - odl));
    tax++;
    if(i > n){
      tax = 0; break;
    }
  }
  cout << tax;
}
