#include "bits/stdc++.h"
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int n;
    cin >> n;

    int A[n];
    int zp = 0, znp = 0;

    for(int i = 0; i < n; i++){
      cin >> A[i];

      if(A[i] % 2 == 0 && i % 2 == 1){
        zp++;
      }
      else if(A[i] % 2 == 1 && i % 2 == 0){
        znp++;
      }
    }

    if(zp != znp)
      cout << -1 << '\n';
    else
      cout << zp << '\n';
  }
}
