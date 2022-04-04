// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

bool IsPrime(int number)
{

    if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    int divisor = 6;
    while (divisor * divisor - 2 * divisor + 1 <= number)
    {

        if (number % (divisor - 1) == 0)
            return false;

        if (number % (divisor + 1) == 0)
            return false;

        divisor += 6;

    }

    return true;

}

int NextPrime(int a)
{

    while (!IsPrime(++a)) 
    { }
    return a;

}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int x = 2;
    while(true){
      int g = __gcd(x, n-x-1);
      if(g == x) x = NextPrime(x);
      else break;
    }
    cout << x << " " << n-x-1 << " " << 1 << "\n";
    // if(n % 2 == 0)
    //   cout << 2 << " " << n-3 << " " << 1 << "\n";
    // else
    //   cout << 2 << " " << n-4 << " " << 1 << "\n";
  }
}