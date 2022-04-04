// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  int D[n];
  D[0] = 0;
  for(int i = 1; i < n; i++){
    cin >> D[i];
  }
  int sum = 0;
  sort(D, D + n);
  for(int i = 0, j = n; i < n;){
    if(D[i] < D[j]){
      i++;
      j--;
      sum++;
    }
    else
      goto end;
  }
  end:
    cout << sum;
}
