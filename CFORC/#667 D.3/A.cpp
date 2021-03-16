#include "bits/stdc++.h"
using namespace std;


int calc(int a, int b){
   int wynik = 0;

   if(a == b)
      return 0;
   else if(a > b)

   else
}


int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   while(t--){
      int a, b; cin >> a >> b;

      cout << calc(a, b) << '\n';
   }
}
