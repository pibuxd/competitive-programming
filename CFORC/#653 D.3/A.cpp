#include "iostream"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t; cin >> t;

   while(t--){
      int x, y, n; cin >> x >> y >> n;

      long long wynik = n + y - (n % x);

      if(n < wynik)
         wynik -= x;

      cout << wynik << '\n';
   }
}
