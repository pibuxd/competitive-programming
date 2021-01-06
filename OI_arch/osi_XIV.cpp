#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e4+7
const int MXN = 2e5;
int n, n2;
int T[MXN+1];
int Pow[(MXN/2)+1];
int 

int SumOfDifferent(int i){

}

int main() {
   cin >> n;
   n2 = n / 2;

   for(int i = 1; i <= n; i++){
      cin >> T[i];
   }

   Pow[0] = 1;
   for(int i = 1; i <= n2; i++){
      Pow[i] = (Pow[i-1] * 29) % MOD;
   }


   int maximum = 0, sum = 0;
   vector<int> K;

   for(int i = 1; i <= n2; i++){
      int sum = SumOfDifferent(i);

      if(sum == maximum){
         K.push_back(i);

      }  else if(sum > maximum){
         maximum = sum;
         K.clear();
         K.push_back(i);
      }
   }
}