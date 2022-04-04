// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    map<char, int> m;
    for(char c : s){
      m[c]++;
    }
    int ans = 0;
    bool one = 0;
    for(char c = 'a'; c <= 'z'; c++){
      if(m[c] > 1) ans++;
      else if(m[c] == 1){
        one = 1 ? !one : 0;
        if(!one) ans++;
      }
    }
    cout << ans << "\n";
  }
}