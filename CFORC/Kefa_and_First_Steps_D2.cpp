// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "iostream"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n; cin >> n;

   int V[n];
   for(int i = 0; i < n; i++){
      cin >> V[i];
   }

   int wynik = 1, counter = 1;

   for(int i = 0; i < n-1; i++){
      if(V[i] <= V[i+1]){
         counter++;
         wynik = max(wynik, counter);
      }  else{
            counter = 1;
         }
   }

   cout << wynik;

}
