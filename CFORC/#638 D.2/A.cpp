#include <iostream>
using namespace std;

int power(int a){
  int b = 2;
  for(int i = 1; i < a; i++){
     b *= 2;
  }
  return b;
}

int main(){
  int t, n, i;
  long long a = 0, b = 0, x = 0;
  cin >> t;
  while(t--){
    cin >> n;
    a += power(n);
    n /= 2;
    n--;
    x = 1;
    i = 1;
    while(i <= n){
      x *= 2;
      a += x;
      i++;
    }
    n *= 2;
    n++;
    while(i <= n){
      x *= 2;
      b += x;
      i++;
    }
    cout << abs(a - b) << '\n';
    a = 0;
    b = 0;
  }
}
