#include "bits/stdc++.h"
using namespace std;

int main(){
   int t; cin >> t;

   while(t--){
      int x, y, z; cin >> x >> y >> z;
      int a, b, c;

      if(x > y && x > z){
         if(x > z){
            if(y < z){
               a = x; b = y; c = a - b;
            }
            else if(y == z){
               a = x; b = y; c = z;
            }
            else if(y > z){
               goto no;
            }
         }
         else
      }

      cout << "YES\n" << a << ' ' << b << ' ' << c << '\n';
      goto end;

      no:
      cout << "NO\n"

      end:;

   }
}
