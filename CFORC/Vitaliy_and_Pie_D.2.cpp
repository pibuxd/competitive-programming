// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n; cin >> n;
   n--;

   int KEY[30];

   for(int i = 0; i < 30; i++){
      KEY[i] = 0;
   }


   int ans = 0;

   for(int i = 0; i < n; i++){
      char small, big; cin >> small >> big;

      int x = small - 96, y = big - 64;

      KEY[x]++;


      if(KEY[y] > 0)
         KEY[y]--;
      else
         ans++;


   }

   cout << ans;
}
