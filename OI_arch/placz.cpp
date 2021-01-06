#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   string A; cin >> A;
   int t; cin >> t;

   int alen = A.size();


   while(t--){
      string B; cin >> B;
      int a; cin >> a;

      int blen = B.size();


      for(int i = 0; i < blen; i++, a++){
         if(A[a] != B[i])
            goto no;
      }

      goto yes;
      no:
         cout << "NIE" << '\n';
         goto end;

      yes:
         cout << "TAK" << '\n';

      end:;
   }
}
