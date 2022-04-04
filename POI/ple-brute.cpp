// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll n, sum_all = 0;

int main(){
  fastio;
  cin >> n;
  vector<ll> plecak(n+1);

  for(ll i = 1; i <= n; i++){
    cin >> plecak[i];
    sum_all += plecak[i];
  }

  for(ll it = 1, sum = 1, kit = 1, k = 1; kit < n; it++, sum = it, k = kit){
    for(ll i = 1; i <= n; i++){
      if(sum - plecak[i] >= 0){
        k--;
        sum -= plecak[i];
      }

      if(k == 0){
        cout << it << ' ';
        kit++;
        break;
      }
    }
  }

  cout << sum_all;
}