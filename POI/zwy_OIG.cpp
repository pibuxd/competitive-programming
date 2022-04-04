// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, Z[100001], mx = 0; cin >> n;
  char L = 'A', l;
  for(int i = 0; i < n; i++){
    cin >> Z[i];
    if(Z[i] > mx) mx = Z[i];
  }
  for(int i = 0; i < n; i++){
    if(Z[i] == mx){
      l = L + i; cout << l;
    }
  }
}
