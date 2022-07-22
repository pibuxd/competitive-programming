#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int a, b;
    cin >> a >> b;

    int kt = a > b;
    if(b > a)
      swap(a, b);

    while(a > b){
      if(kt) cout << '0';
      else cout << '1';
      a--;
    }
    while(a--){
      if(kt) cout << "10";
      else cout << "01";
    }

    cout << '\n';
  }
}