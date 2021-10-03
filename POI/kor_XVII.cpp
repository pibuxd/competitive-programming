#include "bits/stdc++.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct StringHash {
   const int p = 29, MOD = 1e9+1;
   int n, maximum;
   vector<int> hashes1, hashes2, powers;

   StringHash(int _n){
      n = _n;
      hashes1.resize(n+1);
      hashes2.resize(n+1);
      powers.resize(n+1);
      powers[0] = 1;

      for(int i = 1; i <= n; i++){
         powers[i] = powers[i-1] * p % MOD;
      }
   }

   int generate(const vector<int> &sznury){
      set<int> rodzaje;
      
      for(int i = 1; i <= n; i++){
         int hsh = sznury[i] * p % MOD;
         hashes1[i] = hsh;
         hashes2[i] = hsh;
         rodzaje.insert(hsh);
      }

      maximum = rodzaje.size();
      return maximum;
   }

   int findDifferent(int x, const vector<int> &sznury){
      set<int> rodzaje;
      hashes1[1] = hashes2[1] = 0;

      for(int i = 1; i <= x; i++){
         hashes1[1] += sznury[i] * powers[i+x-1] % MOD;
         hashes2[1] += sznury[i] * powers[x+x-i] % MOD;
         rodzaje.insert(hashes1[1]);
         rodzaje.insert(hashes2[1]);
      }

      for(int i = x + 1; i <= n - x; i += x){
         hashes1[i] -= sznury[i-1] * powers[(i-1)%x] % MOD;
         hashes1[i] += sznury[i+x-1] * powers[(i+x-1)%x] % MOD;
         hashes1[i] += sznury[i+x-2] * powers[(i+x-2)%x] % MOD;
         rodzaje.insert(hashes1[i]);

         hashes2[i] -= sznury[i-1] * powers[(i-1)%x-x%x] % MOD;
         hashes2[i] += sznury[i+x-1] * powers[(i+x-1)%x-x%x] % MOD;
         hashes2[i] += sznury[i+x-2] * powers[(i+x-2)%x-x%x] % MOD;
         rodzaje.insert(hashes2[i]);
      }

      return rodzaje.size();
   }
};

int main(){
   fastio;
   int n;
   cin >> n;

   vector<int> sznury(n+1);
   for(int i = 1; i <= n; i++){
      cin >> sznury[i];
   }

   StringHash hashes(n);
   int maximum = hashes.generate(sznury);
   vector<int> ans = {1};

   for(int i = 2; maximum <= n/i; i++){
      int hsh = hashes.findDifferent(i, sznury);

      if(maximum == hsh ){
         ans.push_back(i);
      } else if(maximum < hsh){
         maximum = hsh;
         ans.clear();
         ans.push_back(i);
      }
   }

   cout << maximum << ' ' << ans.size() << '\n';
   
   for(int i : ans){
      cout << i << ' ';
   }
}