// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;
  // cout << "\n";

  while(t--){
    string s, t;
    string ans = "";

    cin >> s >> t;
    int m1 = min({t[0]-(int)'a', t[1]-(int)'a', t[2]-(int)'a'});
    int m2, m3;
    if(t[1] > t[2]) m2 = t[2]-'a', m3 = t[1]-'a';
    else m3 = t[2]-'a', m1 = t[1]-'a';
    string _t = t;
    sort(_t.begin(), _t.end());

    vector<int> oc(27);

    for(int i = 0; i < s.size(); i++){
      oc[(int)s[i]-'a']++;
    }
    vector<int> _oc = oc;

    for(int i = 0; i < s.size(); i++){
      for(int j = 0; j < 26; j++){
        if(t[1]-(int)'a' == j && _t == t && oc[t[2]-(int)'a'] > 0 && !(_oc[t[0]-(int)'a'] == 0 || _oc[t[1]-(int)'a'] == 0 || _oc[t[2]-'a'] == 0))
          continue;
        if(oc[j] > 0){
          oc[j]--;
          ans += (char)('a'+j);
          goto next;
        }
       
      }
      next:;
    }

    cout << ans << "\n";
  }
}