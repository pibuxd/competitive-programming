#include "bits/stdc++.h"
using namespace std;

const int p = 29;
const int MXN = 2e5;
const int MOD = 1e9+7;
int T[MXN+1];
int n, n2;
int Pot[(MXN/2)+1];

int SumOfDiff(int x){
   int sum = 0;
   set<int> Hash;
   int h = x / 2;
   int s = n / x;

   for(int it = 1, k = 1, i = 1; it <= s; it++, k = 1){
      while(k < x){
         const int jd = (T[i] * Pot[abs(k - h)]) % MOD;
         if(*Hash.lower_bound(jd) != jd){
            Hash.insert(jd);
            sum++;
         }
         i++;
         k++;
      }
   }

   return sum;
}

int main(){
   cin >> n;
   n2 = n / 2;

   for(int i = 1; i <= n; i++){
      cin >> T[i];
   }

   Pot[0] = 1;
   for(int i = 1; i <= n; i++){
      Pot[i] = (Pot[i-1] * p) % MOD;
   }

   int maximum = 0;
   vector<int> which;

   for(int i = 1, sum = 0; i <= n2; i++){
      sum = SumOfDiff(i);

      if(sum == maximum){
         which.push_back(i);
      }  else if(sum > maximum){
         maximum = sum;
         which.clear();
         which.push_back(i);
      }
   }

   cout << maximum << ' ' << which.size() << '\n';
   for(int x : which){
      cout << x << ' ';
   }
}