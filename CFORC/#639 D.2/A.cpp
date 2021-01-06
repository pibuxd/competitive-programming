#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0);
  int t;
  cin >> t;

  while(t--){
    int n, m;
    cin >> n >> m;
    if(n == 1 || (n == 2 && m == 2) || m == 1)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
