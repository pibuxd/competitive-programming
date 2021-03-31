#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   string s; cin >> s;

   int ifcan = 0;

   vector<int> firsts;
   for(int i = 0; i < s.size(); i++){
      if(s[i] == s[0]){
         ifcan++;
         firsts.push_back(i);
      }
   }

   if(ifcan < 3) //no
      cout << "Just a legend";

   else{
      int which = 1;

      while(true){
         int ile = 0;
         char search = s[which];
         vector<int> to_erase;

         for(int i = 0; i < firsts.size(); i++){
            if(s[firsts[i] + which] == search){
               ile++;
            }
            else{
               to_erase.push_back(i);
            }
         }

         for(int i = 0; i < to_erase.size(); i++){
            firsts.erase(firsts.begin() + to_erase[i]);
         }

         if(ile < 3)
            break;

         which++;
      }

      for(int i = 0; i < which; i++)
         cout << s[i];
   }
}
