// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    int k, wynik; cin >> k;

    if(k / 100 == 0){
      int s = 0, d = k/10, j = k%10;
      if(j > d && (j % 3 >= d % 3)){
        wynik = k;
        goto end;
      }
    }
    else if(k / 100 == 1){
      int s = 1, d = (k-100)/10, j = k%10;
      if(){

      }
    }
    else if(k / 100 == 2){
      int s = 1, d = (k-200)/10, j = k%10;
      if(){

      }
    }
    end:
    cout << wynik << '\n';
  }
}
