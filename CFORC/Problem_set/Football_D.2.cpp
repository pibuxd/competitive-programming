#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;
   int a = 1, b = 0;

   string s; cin >> s;

   string x = s;
   string y = "";
   t--;
   int z = 0;
   while(t--){
      string s; cin >> s;

      if(s != x && z == 0){
         z = 1;
         y = s;
      }

      if(s == x)
         a++;

      else if(s == y)
         b++;
   }

   if(a > b)
      cout << x;
   else
      cout << y;
}
