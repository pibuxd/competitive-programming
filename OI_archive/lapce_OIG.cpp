#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, k, n, sum = 1;
  cin >> N;
  while(N--){
    cin >> k >> n;
    int DP[n] = {1};
    if(k == 1)
      goto end;
  DP[0] = DP[1] = 1;
  for(int i = 2; i <= n; i++){
    if(i % k != 0)
      DP[i] = DP[i-1];
    else
      DP[i] = DP[i-1] + DP[i/k];
  }
    end:
    cout << DP[n] % 1000000009 << '\n';
    sum = 1;
  }
}
