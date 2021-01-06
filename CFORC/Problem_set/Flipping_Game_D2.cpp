#include "bits/stdc++.h"
using namespace std;

int main(){ //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n; cin >> n;
   bool B[n];

   for(int i = 0; i < n; i++){
      cin >> B[i];
   }

   int pref[n+1];
   pref[0] = 0;
   for(int i = 1; i <= n; i++){
      pref[i] = pref[i-1] + B[]
   }
}
