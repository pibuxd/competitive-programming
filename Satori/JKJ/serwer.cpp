#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    int n, k;
    cin >> n >> k;

    int sum = 1, x = k, A[n];

    for(int i = 0; i < n; i++){
      cin >> A[i];

      if(A[i] - A[i-1] < 1000){
        if(x > 0){
          x--;
        }
        else{ //x == 0
          x = k;
          sum++;
        }
      }
    }
    cout << sum << '\n';
  }
}
