#include "bits/stdc++.h"
using namespace std;

int main(){
   int t; cin >> t;

   for(int i = 1; i <= t; i++){
      int n; cin >> n;

      char I[n];
      for(int i = 0; i < n; i++){
         cin >> I[i];
      }

      char O[n];
      for(int i = 0; i < n; i++){
         cin >> O[i];
      }


      cout << "Case #" << i << ":\n";

      for(int i = 0; i < n; i++){

         char last = 'N';
         for(int j = 0; j < n; j++){

            if((i == j && j == i) || (((I[j] == 'Y' && O[i] == 'Y') && (i - j == 1 || j - i == 1)) || (last == 'Y' && O[j-1] == 'Y' && I[j] == 'Y'))){
               cout << 'Y';
               last = 'Y';
            }
            else{
               cout << 'N';
               last = 'N';
            }
         }

         cout << '\n';
      }
   }
}
