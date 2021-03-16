#include <bits/stdc++.h>
using namespace std;

int main(){ //ios_base::sync_with_stdio(0);
  int t; cin >> t;

  while(t--){
    int n, k;
    cin >> k >> n;
    int x = n / 4; //ile kartek
    int a;

    if(n > k / 2){ //prawa (ktora kartka)
      a = (k - n) / 2 + 1;
    }
    else{ //lewa (ktora kartka)
      a = ceil(n / 2);
    }



    if(n % 2 == 0 && k / 2 >= n){ //2
      cout << n-1 << ' ';
      cout << k-(2*(a-1))-1 << ' ';
      cout << k-(2*(a-1)) << '\n';
    }

    else if(n % 2 == 0 && k / 2 < n){ //4
      cout << (2*a)-1 << ' ';
      cout << 2*a << ' ';
      cout << n-1 << '\n';
    }

    else if(n % 2 != 0 && k / 2 >= n){ //1
      cout << n+1 << ' ';
      cout << k-(2*(a))-1 << ' ';
      cout << k-(2*(a)) << '\n';
    }

    else if(n % 2 != 0 && k / 2 < n){ //3
      cout << (2*a)-1 << ' ';
      cout << 2*a << ' ';
      cout << n+1 << '\n';
    }

  }
}
