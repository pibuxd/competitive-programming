#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

string cezar(const string &s){
  auto ssiz = s.size();
  string after = "";

  for(int i = 0; i < ssiz; i++){
    if(s[i] + 13 > 'z'){
      int to = 'z' - s[i];
      after += (char)('a' + 13 - to - 1);
    }
    else
      after += s[i] + 13;
  }

  return after;
}

int main(){
  fastio;
  int z;
  cin >> z;
  while(z--){
    string s;
    cin >> s;
    string ans = cezar(s);
    string check = cezar(ans);
    if(check == s)
      cout << ans << "\n";
    else
      cout << "NIE\n";
  }
}