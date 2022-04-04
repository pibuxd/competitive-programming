// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int solve(string s){
  int x = 0;
  for(char c : s){
    int f = (int)c - (int)'0';
    if(f % 2 == 0)
      x++;
  }

  int last = (int)s[s.size()-1] - (int)'0';
  int first = (int)s[0] - (int)'0';
  if(last % 2 == 0){
    return 0;
  }
  if(first % 2 == 0)
    return 1;
  if(x > 0) return 2;
  return -1;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
}