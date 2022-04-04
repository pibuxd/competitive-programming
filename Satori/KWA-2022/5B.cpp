// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n;
vector<long long> a;

long long solve(){
  long long ans = 0;

  for(long long i = 1; i <= n; i++){
    ans += max((long long)0, a[i] - a[i-1]);
  }
  return ans;
}

int main(){
  fastio;
  long long t;
  cin >> t;

  while(t--){
    cin >> n;
    a.resize(n+1);

    for(long long i = 1; i <= n; i++) cin >> a[i];
    cout << solve() << "\n";
  }
}