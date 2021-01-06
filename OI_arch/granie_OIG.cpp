#include <bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(0);
  long long n, D[1000001], A[1000001], p, sum = 0, S[1000001]; cin >> n;
  for(long long i = 0; i < n; i++){
    cin >> D[i];
  } cin >> p;
  for(long long i = 0; i < p; i++){
    cin >> A[i];
  }
  for(long long i = 0; i < n; i++){
    sum += D[i];
    S[sum] = 1;
  }
  for(long long i = 0; i < p; i++){
    if(S[A[i]] == 1) cout << "TAK" << '\n';
    else cout << "NIE" << '\n';
  }
}
