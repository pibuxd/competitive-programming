// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * KMP string matching algorithm
#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(string &s){
  int n = s.size();
  vector<int> pi(n);

  for(int i = 1; i < n; i++){
    int j = pi[i-1];
    while(j > 0 && s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j])
      j++;
    pi[i] = j;
  }

  return pi;
}

int main(){
  string _s, s, p;
  cin >> _s >> p;
  s = p + '#' + _s;

  vector<int> pi = kmp(s);

  int ans = 0;
  for(int l : pi)
    ans += (l == p.size());
  cout << ans;
}