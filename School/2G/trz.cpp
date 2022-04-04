// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 int n;
 cin >> n;

 vector<int> dodatnie(1000001), ujemne(1000001);

 for(int i = 0; i < n; i++){
   int wczytanie;
   cin >> wczytanie;

  if(wczytanie >= 0){
    dodatnie[wczytanie]++;
    if(dodatnie[wczytanie] == 3){
      cout << "TAK";
      return 0;
    }
  }

  else{ //ujemne
    wczytanie *= -1;
    ujemne[wczytanie]++;
    if(ujemne[wczytanie] == 3){
      cout << "TAK";
      return 0;
    }
  }
 }

 cout << "NIE";
}
