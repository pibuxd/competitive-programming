#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   cout << '\n';

   while(t--){
      long long a, b, x, y, n; cin >> a >> b >> x >> y >> n;

      while(n--){
         if(a == b)
            if(x > y)
               b--;
            else
               a--;

         else if((a > b || (b > a && a == x)) && (b > y))
            b--;

         else if((b > a || (a > b && b == y)) && (a > x))
            a--;
            
         else if(a == x && b ==  y)
            break;
      }

      cout << a * b << '\n';
   }
}
