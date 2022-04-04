// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, sum = 0; cin >> n; int A[n], B[n];
  for(int i = 0; i < n; i++){ cin >> A[i] >> B[i]; }
  sort(A, A+n); sort(B, B+n);
  for(int i = 0; i < n; i++){
    if(A[i] <= B[i]) sum += B[i] - A[i];
    else goto koniec;
  }
  cout << sum; goto koniec2;
  koniec:
  cout << "NIE";
  koniec2:;
}
