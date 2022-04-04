// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){
   long long n; cin >> n;

   long long x = 0;

   while(n / 2 != 0){
      if(n % 2 == 1)
         x++;

      n /= 2;
   }

   cout << x + 1;
}
