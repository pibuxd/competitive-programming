// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){ fastio;
  int n, d; cin >> n >> d;

  bool last = false;
  int ile = 0;
  set<int> A;

  for(int i = 0; i < n; i++){
    int c, a; cin >> c >> a;

    if(c == 1)
      A.insert(a);
    else
      A.erase(A.find(a));

    if(A.count(a+d) || A.count(a-d)){
      if(c == -1 && (A.count(a+d) && A.count(a-d)))
        ile -= 2;
      else if(c == -1 && (A.count(a+d) || A.count(a-d)))
        ile -= 1;
      else if(c == 1 && (A.count(a+d) && A.count(a-d)))
        ile += 2;
      else if(c == 1 && (A.count(a+d) || A.count(a-d)))
        ile += 1;

    if(ile == 0)
      last = false;
    else
      last = true;
    }

    if(last)
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
