#include <iostream>
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m;
    long long x = (n / 2), min = 1000000000, l;
    long long sum = 0;

    if(n == 1){
      cout << '0' << '\n';
      goto koniec;
    }
    if(n == 2){
      cout << m << '\n';
      goto koniec;
    }

    while(x--){
      l = (m / (x + 1));
      m -= l;
      sum += (2 * l);
      if((min > l) && (n % 2 == 0))
        min = l;
    }
    if((min < l) && (n % 2 == 0)){
      sum -= min;
    }
    cout << sum << '\n';
    koniec:;
  }
}
