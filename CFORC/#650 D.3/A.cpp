#include "bits/stdc++.h"
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    string a, b = "";
    cin >> a;
    b = b + a[0] + a[1];

    for(int i = 3; i < a.size(); i += 2){
      b += a[i];
    }
    cout << b << '\n';
  }
}
