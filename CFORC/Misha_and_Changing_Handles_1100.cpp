// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){ fastio;
  int n;
  cin >> n;

  map<string, string> m1, m2;
  vector<string> ans;

  while(n--){
    string a, b;
    cin >> a >> b;

    if(m1[a] == "" && m2[a] == ""){ // new word
      ans.push_back(a);
      m1[a] = b;
      m2[b] = a;
    }

    else{
      m2[b] = m2[a];
      m1[m2[b]] = b;
    }
  }

  cout << ans.size() << "\n";
  for(string s : ans){
    cout << s << " " << m1[s] << "\n";
  }
}