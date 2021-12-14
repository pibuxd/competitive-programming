#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
   int t; cin >> t;

   map<string, int> name;

   cout << '\n';

   while(t--){
      string s; cin >> s;


      if(!name[s]){
         name[s] = 1;
      }
      else{
         name[s]++;
      }

      string number = to_string(name[s] - 1);

      string result = s + number;


      if(name[s] == 1)
         cout << "OK" << '\n';
      else
         cout << result << '\n';

   }
}
