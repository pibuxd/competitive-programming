#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){ 
    int n, k;
    cin >> n >> k;

    int A[n], B[n];
    long long sum = 0;
    for(int i = 0; i < n; i++){
      cin >> A[i];
      sum += A[i];
    }
    for(int i = 0; i < n; i++){
      cin >> B[i];
    }

    sort(A, A + n);
    sort(B, B + n);

    for(int i = 0, j = (n - 1); i < n && k > 0; i++, j--){
      if(A[i] < B[j]){
        sum += (B[j] - A[i]);
        k--;
      }
    }
    cout << sum << '\n';
  }
}
