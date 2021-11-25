#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

ll m;
vector<ll> fib(87); // max m dla jednego prostokata to 679891637638612258, n = 86

void fibonacci(){
  fib[1] = 1;
  fib[2] = 2;

  for(int i = 3; i <= 86; i++){
    fib[i] = fib[i-1] + fib[i-2];
  }
}

ll foo(ll number){
  ll ans = 0;
  ll t = number;
  if(t == 1)
    return 2;

  for(int i = 86; i >= 4; i--){
    if(fib[i] == 8 || fib[i] == 144) continue;

    while(t % fib[i] == 0){
      ans += i + 1;
      t /= fib[i];
    }
  }

  ll dwojki, trojki;
  dwojki = trojki = 0;

  while(t % 2 == 0 || t % 3 == 0){
    if(t % 2 == 0) t /= 2, dwojki++;
    if(t % 3 == 0) t /= 3, trojki++;
  }

  while(true){
    if(dwojki >= 4 && trojki >= 2){
      dwojki -= 4, trojki -= 2;
      ans += 11 + 1; // f(11) = 144
    }
    else if(dwojki >= 3){
      dwojki -= 3;
      ans += 5 + 1; // f(5) = 8;
    }
    else break;
  }

  ans += 3 * dwojki;
  ans += 4 * trojki;

  if(t > 1)
    return 0;
  return ans;
}

ll test(ll num){
  ll ans = foo(num);

  if(ans == 0)
    return 0;
  else
    return ans - 1;
}

void test_file(){
  ifstream in, out;
  in.open ("dom.in");
  out.open ("dom.out");

  ll num, good;
  while(in >> num && out >> good){
    if(foo(num)-1 != good){
      cout << "ERROR: " << num << " -> " << foo(num)-1 << " should be " << good;
      break;
    }
  }
}

ll test_xor(ll start, ll end){
  ll res = 0;

  for(ll i = start; i <= end; i++){
    res ^= test(i);
  }
  return res;
}

void solve(){
  cin >> m;

  ll ans = foo(m);

  if(ans == 0)
    cout << "NIE";
  else
    cout << ans - 1;
}

int main(){
  fastio;
  fibonacci();

  solve();
  // for(ll i = 1, r = 0; i <= 1000000000; i++){
  //   r ^= test(i);
  //   if(i % 50000000 == 0)
  //     cout << "1 to " << i << ": " << r << "\n";
  // }
  // test_file();
}