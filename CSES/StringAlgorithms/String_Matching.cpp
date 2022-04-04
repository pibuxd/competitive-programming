// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * KMP string matching algorithm
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  string _s, s, p;
  cin >> _s >> p;
  s = p + '#' + _s;
  int n = s.size(), m = p.size();

  vector<int> pi(n);

  for(int i = 1; i < n; i++){
    int j = pi[i-1];
    while(j > 0 && s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j])
      j++;
    pi[i] = j;
  }

  int ans = 0;
  for(int l : pi)
    ans += (l == p.size());
  cout << ans;
}