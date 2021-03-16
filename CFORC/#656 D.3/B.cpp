#include "bits/stdc++.h"
using namespace std;

int main(){
   int t; cin >> t;

   while(t--){
      int n; cin >> n;
      n *= 2;

      int V[n+1], I[n+1];
      for(int i = 1; i <= n; i++){
         cin >> V[i];
         I[i] = 2;
      }

      for(int i = 1; i <= n; i++){
         if(I[V[i]] == 2){
            cout << V[i] << ' ';
            I[V[i]]--;
         }
      }

      cout << '\n';
   }
}
