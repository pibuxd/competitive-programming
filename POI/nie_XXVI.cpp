// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string A, B; cin >> A >> B;

  map<char, bool> X;

  for(int i = 0; i < A.size(); i++){
    X[A[i]] = true;
  }
  for(int i = 0; i < B.size(); i++){
    if(X[B[i]] == true){
      cout << B[i];
      return 0;
    }
  }
}
