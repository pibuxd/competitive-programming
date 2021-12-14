#include "iostream"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n, m, a, b; cin >> n >> m >> a >> b;

   int sum = 0;

   if(b >= m * a)
      sum = a * n;

   else{
      sum += (n / m) * b;
      if(((n % m) * a) <= b)
         sum += (n % m) * a;
      else
         sum += b;
   }


   cout << sum;
}
