// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int p = 29;
const ll mod = 10657331232548839;
const int MXN = 2e5;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T;
  cin >> T;
  
  vector<ll> pot(2000003);
  vector<ll> sumPref(2000003);

  while(T--){
    int Z;
    string S;
    cin >> S >> Z;
    unsigned int siz = S.size();
    
    sumPref[0] = 0;
    pot[0] = 1; 
    pot[1] = p;

    for(int i = 1; i <= siz; i++){
      sumPref[i] = (sumPref[i-1] + (pot[i] * (S[i-1]-96))) % mod;
      pot[i+1] = (pot[i] * p) % mod;
    }

    while(Z--){
      int x, y, r;
      cin >> x >> y >> r;
      
      if(x == y){
        cout << "TAK\n";
        continue;
      }

      if(x < y){
        if((((sumPref[x+r-1] - sumPref[x-1]) * pot[y-x]) % mod) == ((sumPref[y+r-1] - sumPref[y-1]) % mod))
          cout << "TAK\n";
        else
          cout << "NIE\n";
      }
      else{
        if(((sumPref[x+r-1] - sumPref[x-1]) % mod) == (((sumPref[y+r-1] - sumPref[y-1]) * pot[x-y]) % mod))
          cout << "TAK\n";
        else
          cout << "NIE\n";
      } 
    }
  }
}
