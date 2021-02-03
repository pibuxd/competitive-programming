#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    int i = 1, ile = 0, k = 0;
    next:

    if(n == 0 || n == 1)
      goto print;

    while(n > 0){
      n -= i*3 - 1;
      i++;
    }
    ile++;
    if(n < 0){
      i--;
      n += i*3 - 1;
    }
    cout << i-1 << " ";
    i = 0;
    goto next;
    print:
    cout << "   " << ile << '\n';
  }
}
