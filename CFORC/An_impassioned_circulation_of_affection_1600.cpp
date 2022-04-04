// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * 2P (Two pointers)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q, len;
string s;

int main(){
  fastio;
  cin >> n >> s >> q;

  while(q--){
    int m;
    char c;
    cin >> m >> c;
    
    int i, ans, len, avail, f;
    i = ans = len = f = 0;
    avail = m;

    while(i < n){
      if(s[i] == c){
        len++;
        i++;
        ans = max(ans, len);
      }
      else if(avail){
        avail--;
        len++;
        i++;
        ans = max(ans, len);
      }
      else{
        len--;
        if(s[f] != c)
          avail++;
        f++;
      }
    }
    cout << ans << "\n";
  }
}