// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

string encrypt(string text, int s){
  string result = "";

  for(int i=0;i<text.length();i++)
    result += char(int(text[i]+s-97)%26 +97);

  return result;
}

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    string s;
    cin >> s;
    string en = encrypt(s, 13);
    string _s = encrypt(en, 13);

    if(s == _s)
      cout << en;
    else
      cout << "NIE";
    cout << "\n";
  }
}