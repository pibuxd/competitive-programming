#include <bits/stdc++.h>
using namespace std;

// prefix sums

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n, q;
  cin >> n >> q;

  long long tab[n+1];
  long long prefixSum[n+1];
  prefixSum[0] = 0;

  for(long long i = 1; i <= n; i++){
    cin >> tab[i];
    prefixSum[i] = prefixSum[i-1] + tab[i];
  }

  while(q--){
    long long a, b;
    cin >> a >> b;

    long long sum = prefixSum[b] - prefixSum[a-1];
    cout << sum << '\n';
  }
}