// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

string s, p;
int slen, plen;

int foo(int l, int r){
  int res = 0, first = -1, last = -1;

  for(int i = 0; i < slen; i++){
    int j = l+i;

    if(s[i] != p[j]){
      if(first == -1) first = i;
      last = i;
    }    
  }

  if(first == -1) return 0;
  return last - first + 1;
}

int main(){
  fastio;
  cin >> s >> p;

  slen = s.size(), plen = p.size();

  int l = 0, r = slen-1, mn = slen;

  while(r <= plen-1){
    mn = min(mn, foo(l, r));
    l++, r++;
  }

  cout << mn;
}