// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
   string a;
   cin >> a;

   string hello = "hello";
   int len = a.size();
   int i = 0, j = 0;

   while(i < len){
      if(a[i] == hello[j])
         j++;
      if(j == 5)
         break;
      i++;
   }

   if(j == 5)
      cout << "YES" << '\n';
   else
      cout << "NO" << '\n';
}
