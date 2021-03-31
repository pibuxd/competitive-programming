#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, t; cin >> n >> t;

  int Teleport[n+1];

  Teleport[n] = 0;
  for(int i = 1; i <= n-1; i++){
    cin >> Teleport[i];
  }

  int i = 1;
  while(true){
    i += Teleport[i];

    if(i == t){
      cout << "YES";
      return 0;
    } else if(i > t){
      cout << "NO";
      return 0;
    }
  }
}
