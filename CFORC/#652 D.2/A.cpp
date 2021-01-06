#include "bits/stdc++.h"
using namespace std;

string isBeautiful(int a){
   if(a % 4 == 0)
      return "YES";
   else
      return "NO";
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   while(t--){
      int a; cin >> a;

      cout << isBeautiful(a) << '\n';
   }
}
