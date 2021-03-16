#include "iostream"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   while(t--){
      int a, b;
      cin >> a >> b;

      int reszta = a % b;

      if(reszta != 0)
         cout << b - reszta << '\n';
      else
         cout << 0 << '\n';
   }
}
