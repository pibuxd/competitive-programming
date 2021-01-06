#include "bits/stdc++.h"
using namespace std;

int main(){
   string s;
   cin >> s;

   int len = s.size();
   bool ab = false, ba = false;

   bool last = false;

   for(int i = 0; i < len; i++){
      if(last == false){
         if(s[i] == 'A' && s[i+1] == 'B'){
            if(s[i+1] == 'B' && s[i+2] == 'A'){
               if(ab == true && ba == false){
                  ba = true;
                  last = true;
               }
               else if(ab == false){
                  ab = true;
                  last = true;
               }
            } else if(ab == false){
               ab = true;
               last = true;
            }

         }

         else if(s[i] == 'B' && s[i+1] == 'A'){
            if(s[i+1] == 'A' && s[i+2] == 'B'){
               if(ba == true && ab == false){
                  ab = true;
                  last = true;
               }
               else if(ba == false){
                  ba = true;
                  last = true;
               }
            }  else if(ba == false){
                  ba = true;
                  last = true;
               }
         }
      }
   }


   if(ab == true && ba == true)
      cout << "YES";
   else
      cout << "NO";
}
