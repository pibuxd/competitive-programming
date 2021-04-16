#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

map<ll, bool> pot;

void make_pot(){
  for(ll i = 1; (i*i*i) <= 1000000000000000; i++){
    pot.insert({i*i*i, 1});
    if(i == 7993)
      cout << "XDD";
  }
}

bool solve(ll x){
  for(ll a = 1; (a*a*a) <= 1000000000000000; a++){
    a = a*a*a;

    if(pot[x-a]){
      cout << a << ',' << x-a << ' ';
      return true;
    }
    if(a >= x)
      return false;
  }

  return false;
}

int main(){
  fastio;
  int t;
  cin >> t;

  make_pot();

  for(map<ll, bool>::iterator it = pot.begin(); it != pot.end() && (it->first) <= 100; it++){
    cout << it->first << ' ';
  }

  for(ll x; t--;){
    cin >> x;
    if(solve(x)) cout << "YES\n";
    else cout << "NO\n";
  }
  ll s = 7993*7993*7993;
  cout << pot[s];
}