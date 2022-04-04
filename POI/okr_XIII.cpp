// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * KMP string matching algorithm
// * but searching for the minimum prefix-suffix
#include <bits/stdc++.h>
using namespace std;
#define int long long

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

signed main(){
  int n; cin >> n;
  string s; cin >> s;

  vector<int> pi = kmp(s);

  int ans = 0;
  for(int i = 1; i < n; i++){
    if(pi[i] == 0) continue;
    if(pi[pi[i]-1] != 0) pi[i] = pi[pi[i]-1];

    int l = i+1 - pi[i];  
    ans += l;
    // cout << l << " ";
  }
  // cout << "\n";
  cout << ans;
}