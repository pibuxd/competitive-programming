#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int temp = n/3;
    if(n%3 > 1)
      temp++;
    int _temp = n-(temp*2);
    cout << _temp << " " << temp << "\n";
  }
}