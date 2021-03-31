#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, k, suma = 0, it = 0; cin >> n >> k;
  int A[n], B[n]; long long sum[n];
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < n; i++) cin >> B[i];
  for(int i = 0; i < n; i++) sum[i] = ((A[i] / 2) + 1) * B[i];
  sort(sum, sum + n);
  while((suma + sum[it]) <= k){ suma += sum[it]; it++; }
  cout << it;
}
