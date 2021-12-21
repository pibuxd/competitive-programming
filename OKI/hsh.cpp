#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define M ((int)1e9+7)
#define P (int)(26)

int _n, n;
vector<char> _s, s;

signed main(){
  fastio;
  cin >> _n >> n;
  _s.resize(_n+1);
  s.resize(n+1);
  for(int i = 1; i <= _n; i++) cin >> _s[i];
  for(int i = 1; i <= n; i++) cin >> s[i];

  int _h = 0, h = 0, p = 1;
  for(int i = 1; i <= _n; i++, p *= P){
    _h += (p * (int)(_s[i] - 'a' + 1)) % M;
    h += (p * (int)(s[i] - 'a' + 1)) % M;
  }
  p /= P;

  if(_h == h)
    cout << 1 << "\n";

  for(int i = _n+1; i <= n; i++){
    h -= (int)(s[i-_n] - 'a' + 1) % M;
    h /= P;
    h += ((int)(s[i] - 'a' + 1) * p) % M;
    if(_h == h)
      cout << i-_n+1 << "\n";
  }
}