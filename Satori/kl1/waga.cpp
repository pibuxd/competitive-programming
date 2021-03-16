#include <bits/stdc++.h>
using namespace std;

int main(){ //ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    int n; cin >> n;
    int l = n, p = n, n2 = n;
    vector<int> L, P;

    if((n+1) % 3 == 0){
      P.push_back(1);
      n++;
      p++;
    }
    else{
      L.push_back(1);
      n--;
      l++;
    }

    int x = 3;

    while((p - l) != n2){
      if((n+x) % 3 == 0){
        P.push_back(x);
        n += x;
        p += x;
      }
      else{
        L.push_back(x);
        n -= x;
        l += x;
      }
      x *= 3;
    }

    for(int i = 0; i < L.size(); i++){
      cout << L[i] << ' ';
    }
    cout << "| ";
    for(int i = 0; i < P.size(); i++){
      cout << P[i] << ' ';
    }
    cout << '\n';

  }
}
