#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n, m;
   cin >> n >> m;

   int film[n+1];
   for(int i = 1; i <= n; i++){
      cin >> film[i];
   }

   int fajnosc[m+1], ile[m+1];
   for(int i = 1; i <= m; i++){
      cin >> fajnosc[i];
      ile[i] = 0;
   }

   int last = film[n], W[m+1], it = n;

   W[m] = fajnosc[film[n]];

   for(int i = (m - 1); i >= 1; i--){
      ile[film[i]]++;

      if((ile[film[i]] == 2 && film[i] == last) || ile[film[i]] == 1){
         W[i] = W[i+1] + fajnosc[film[i]];
         ile[film[i]]--;

         if(last == film[i]){
            it--;
            last = film[it];
         }
      }  else if(ile[film[i]] > 1 && film[i] != last){
            if(ile[film[i]] == 2)
               W[i] = W[i+1] - fajnosc[film[i]];
            else
               W[i] = W[i+1];
         }
         else if(ile[film[i]] > 2 && film[i] == last){
            it--;
            last = film[it];
            ile[film[i]]--;
            if(ile[film[i]] == 1)
               W[i] = W[i+1] + fajnosc[film[i]];
            else
               W[i] = W[i+1];
         }
   }

   int wynik = 0;
   for(int i = 1; i <= m; i++){
      if(W[i] > wynik)
         wynik = W[i];
   }

   cout << wynik;
}
