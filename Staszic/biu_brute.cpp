#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, dni, sum;
vector<int> p, s, c;

int solve(){
  cin >> n;

  p.assign(n+1, 0);
  s.assign(n+1, 0);
  c.assign(n+1, 0);

  sum = 0;

  for(int i = 2; i <= n; i++){ cin >> s[i]; sum += s[i]; }
  for(int i = 2; i <= n; i++) cin >> p[i];
  for(int i = 2; i <= n; i++) cin >> c[i];

  dni = 0;

  while(s[1] < sum){
    dni++;

    vector<int> _s(n+1, 0);
    for(int i = 2; i <= n; i++){
      int push = min(c[i], s[i]);
      s[i] -= push;
      _s[p[i]] += push;
    }

    for(int i = 1; i <= n; i++)
      s[i] += _s[i];
  }
  
  return dni;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--)
    cout << solve() << "\n";
}