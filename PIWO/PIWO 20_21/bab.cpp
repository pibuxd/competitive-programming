#include "bits/stdc++.h"
using namespace std;

bool Baba(string S, int n){
  string baba = "baba";
  int it = 0;

  for(int i = 0; i < n; i++){
    if(S[i] == baba[it])
      it++;
    if(it == 4)
      return true;
    }
  return false;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;

  while(t--){
    string S; cin >> S;

    if(Baba(S, S.size()))
      cout << "Tak" << '\n';
    else
      cout << "Nie" << '\n';
  }
}
