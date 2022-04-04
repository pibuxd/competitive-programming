// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  string s; cin >> s;
  int maximum = 1, curr = 1;

  for(unsigned int i = 0; i < s.size() - 1; i++){
    if(s[i] == s[i+1])
      curr++;
    else{
      maximum = max(maximum, curr);
      curr = 1;
    }
  }
  maximum = max(maximum, curr);
  cout << maximum;
}
