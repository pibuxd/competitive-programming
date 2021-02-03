#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int n, x;
    cin >> n >> x;

    int A[n];
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }

    int sum[n], it = 0;
    sum[0] = 0;

    for(int i = 0; i < n; i++){

  if((sum[it] + A[i]) % x != 0){
        sum[it] += A[i];
      }

  else{
        it++;

        if(A[i] % x == 0){
          sum[it] = 0;
        }
        else{
          sum[it] = A[i];
        }

      }
    }
    it++;
    sort(sum, sum + it);
    cout << sum[it-1] << '\n';
  }
}
