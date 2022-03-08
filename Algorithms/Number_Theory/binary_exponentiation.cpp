// * Binary Exponentiation (exponentiation by squaring)
// * quick power
// a^b = (a^(b/2))^2
// eg. 3^8 = 3^4 * 3^4 = 6561
#include <bits/stdc++.h>
using namespace std;

int quick_power(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans *= a;
    a *= a;
    b /= 2;
  }

  return ans;
}

int main(){
  int a, b;
  cin >> a >> b;

  cout << quick_power(a, b) << "\n";
}