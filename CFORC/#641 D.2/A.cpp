#include <iostream>
using namespace std;

int min_div(int a){
    int i = 3;
    while(a % i != 0){
      i += 2;
        if(i > (a/2))
          return a;
        }
      return i;
}

int main(){ ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n, k;
    cin >> n >> k;

    if(n % 2 != 0){
      n += min_div(n);
      k--;
    }
    n += k * 2;
    cout << n << '\n';
  }
}
