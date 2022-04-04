// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
int n, A[1000], B[1000], k; cin >> n; string a, b, sum;
for(int it = 0; it < n; it++){
  sum = ""; cin >> a >> b >> k;
  for(int i = 0; i < a.size(); i++){
    A[i] = a[i]; B[i] = b[i];
  }
  for(int i = 0; i < a.size(); i++){
    if(A[i] >= B[i] && k > 0 && A[i] > 0){
      A[i] = (B[i] - 1); k--;
    }
  }
  for(int i = 0; i < a.size(); i++){
    sum += A[i];
  }
  if(k == 0)
    cout << sum << endl;
  if(k > 0)
    cout << "-1" << endl;
}
}
