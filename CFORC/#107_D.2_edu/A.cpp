#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  for(int n; t--;){
    cin >> n;
    int sum = 0;

    for(int i = 1, x; i <= n; i++){
      cin >> x;
      
      if(x == 1 || x == 3){
        sum++;
      }
    }

    cout << sum << "\n";
  }
}