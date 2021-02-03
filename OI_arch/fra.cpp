#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, max = 0;
  cin >> n >> k;
  int D[n], K[k];
  for(int i = 0; i < n; i++){
    cin >> D[i];
    if(max < D[i]){
      max = D[i];
    }
  }
  for(int i = 0; i < k; i++){
    cin >> K[i];
  }
  sort(K, K + k);
  for(int i = 0; i < max; i++){
    for(int j = 0; j < n; j++, D[i]--){
      if(D[i] == 0){
        goto end;
      }
      if(K[j] > )
      end:;
    }
  }
}
