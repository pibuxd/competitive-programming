#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int x, y;
    cin >> x >> y;

    string S;
    cin >> S;

    for(char c : S){
      if(y > 0 && c == 'U'){
        y--;
      }
    
      if(y < 0 && c == 'D'){
        y++;
      }
      
      if(x > 0 && c == 'R'){
        x--;
      }
    
      if(x < 0 && c == 'L'){
        x++;
      }
    }

    if(x == 0 && y == 0){
      cout << "YES\n";
    } else{
      cout << "NO\n";
    }
  }
}