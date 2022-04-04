// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

vector<string> potegi_5;

string to_bin(ll x){
  string res = "";
  while(x != 0){
    res += (x % 2 == 0 ? "0" : "1");
    x /= 2;
  }

  reverse(res.begin(), res.end());
  return res;
}

void new_pot(ll x){
  potegi_5.push_back(to_bin(x));
}

void preprocessing(){
  ll x = 1;
  for(int i = 0; i <= 21; i++){
    new_pot(x);
    x *= 5;
  }
  reverse(potegi_5.begin(), potegi_5.end());
}

int main(){
  fastio;
  preprocessing();

  string input;
  cin >> input;

  int licz = 0;
  bool check = false;
  while(input.size() && !check){
    check = true;

    for(int i = 0; i <= 21; i++){
      int xlen = potegi_5[i].size(), it = input.find(potegi_5[i]);

      if(it == string::npos || it != 0)
        continue;
      if(it == 0)
        licz++, input = input.substr(xlen);
      
      check = false;
      break;
    }
  }

  if(input.size() || licz == 0) cout << "-1";
  else cout << licz;
}