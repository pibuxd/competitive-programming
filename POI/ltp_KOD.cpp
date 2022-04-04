// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int n, sq, c; cin >> n; double a;
  for(int it = 0, f = 0; it < n; it++, f = 0){cin >> a; sq = sqrt(a);
    if(a == 1) goto koniec;
    if(a != (sqrt(a)*sqrt(a))) goto koniec;
    for(int i = 2; i < (sq/2); i++){
      if(sq % i == 0){ f = 1; goto koniec; }
    }
    jp:
    cout << "TAK" << '\n'; goto jd;
    koniec:
    cout << "NIE" << '\n';
    jd:;
  }
  }
