#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector<long long> p1(n+1), p2(n+1);
    long long p0 = 0;

    for(int i = 1; i <= n; i++){
      int x;
      cin >> x;
      if(x == i) p0++;
      else if(x > i) p1[x-i]++;
      else p2[i-x]++;
    }

    long long ans = 0;
    if(p0 > 0)
      ans += (p0 * (p0 - 1)) / 2;

    for(int i = 1; i <= n; i++){
      if(p1[i] > 0)
        ans += (p1[i] * (p1[i] - 1)) / 2;
      if(p2[i] > 0)
        ans += (p2[i] * (p2[i] - 1)) / 2;
    }

    cout << ans << "\n";
  }
}