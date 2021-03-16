#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   while(t--){
      int n, k;
      cin >> n >> k;

      int a = n - 2, b = 2;
      int mozliwosci = (n * (n - 1)) / 2;

      string wynik = "";
      for(int i = 0; i < n; i++){
         wynik += 'a';
      }

      wynik[] = 'b';

      cout << wynik << '\n';
   }
}
