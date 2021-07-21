#include "bits/stdc++.h"
using namespace std;

int main(){
  int n;
  cin >> n;
  long long V[n], sum = 1;
  for(int i = 0; i < n; i++)
    cin >> V[i];
  sort(V, V + n);
  for(int i = 0; i < n; i++){
    sum *= (V[i] - i);
  }
  cout << (sum % 1000000007);
}
