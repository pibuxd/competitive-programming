// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// 1 bit - a
// 2 bity - c
// 3 bity - g
// 4 bity - o

int n;
string s; 

int main(){
  fastio;
  cin >> n >> s;
  
  int jed = 0;
  for(char c : s)
    if(c == '1')
      jed++;
  
  jed -= 2 * n;
  if(jed < n || jed > 4*n){
    cout << "NIE";
    return 0;
  }

  jed -= n;
  
  for(int i = 1; i <= n; i++){
    if(jed - 3 >= 0)
      cout << 'o', jed -= 3;
    else if(jed - 2 >= 0)
      cout << 'g', jed -= 2;
    else if(jed - 1 >= 0)
      cout << 'c', jed -= 1;
    else
      cout << 'a';
  }
}