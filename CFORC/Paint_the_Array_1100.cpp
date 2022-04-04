// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector<ll> a(n+1);
    ll gcd1, gcd2;

    for(int i = 1; i <= n; i++){
      cin >> a[i];
      if(i == 1) gcd1 = a[1];
      else if(i == 2) gcd2 = a[2];
      else if(i % 2 == 1) gcd1 = __gcd(gcd1, a[i]);
      else if(i % 2 == 0) gcd2 = __gcd(gcd2, a[i]);
    }

    ll gcd = gcd1;
    ll ans = 0;
    for(int i = 2; i <= n; i += 2){
      if(a[i] % gcd1 == 0)
        ans = gcd2;
    }
    if(ans == 0)
      cout << gcd1 << "\n";
    else{
      ans = 0;
      for(int i = 1; i <= n; i += 2){
        if(a[i] % gcd2 == 0)
          ans = gcd2;
        }
      if(ans == 0)
        cout << gcd2 << '\n';
      else cout << "0\n";
    }


  }
}