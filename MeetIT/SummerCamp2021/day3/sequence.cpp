// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n, sum;
vector<long long> b;

int main(){
  fastio;
  cin >> n;
  b.resize(n+1);
  sum = 0;

  for(long long i = 1; i <= n-1; i++) cin >> b[i];

  sum += b[1];

  for(long long i = 2; i <= n-1; i++){
    sum += min(b[i-1], b[i]);
  }
  sum += b[n-1];
  cout << sum;
}