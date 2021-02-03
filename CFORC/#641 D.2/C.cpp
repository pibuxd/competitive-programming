#include <bits/stdc++.h>
using namespace std;

#define ll long long

int lcm(int a, int b){
  int lc;
  if(a > b)
      lc = a;
   else
      lc = b;
   while(1) {
      if(lc % a == 0 && lc % b == 0){
         return lc;
      }
      lc++;
   }
}

int main(){ //ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
      cin >> A[i];
    }
    ll g2 = 200000;
    for(int i = 0; i < n; i++){
      for(int j = (i + 1); j < n; j++){
        ll a = lcm(A[i], A[j]);
        if(j + 1 >= n){
          j++;
          ll b = lcm(A[i], A[j]);
          ll g = __gcd(a, b);
          g2 = __gcd(g, g2);
        }
      }
    }
    cout << g2 << '\n';
  }
}
