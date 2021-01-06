#include "bits/stdc++.h"
using namespace std;

int main(){
  int n; cin >> n;
  
  vector<int> A(6), B(6), C(6);

  char dyw;
  for(int i = 0, it; i < n; i++){
    cin >> it >> dyw;

    if(dyw == 'A'){
      A[it]++;
    } else if(dyw == 'B'){
      B[it]++;
    } else{
      C[it]++;
    }
  }

  for(int i = 1; i < 5; i++){
    if(!A[i] || !B[i] || !C[i]){
      cout << "NIE";
      return 0;
    }
  }
  
  if(A[5] < 2 || B[5] < 2 || C[5] < 2){
    cout << "NIE";
    return 0;
  }

  cout << "TAK";
}
