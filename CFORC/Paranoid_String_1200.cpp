#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int t; cin >> t;

  while(t--){
    int n; cin >> n;

    int prev, sum = 1;
    char _prev; cin >> _prev;
    prev = _prev == '1';

    for(int i = 2; i <= n; i++){
      char _a; cin >> _a;
      int a = _a == '1';

      if(a != prev) sum += i;
      else sum += 1;
      prev = a;
    }

    cout << sum << "\n";
  }
}