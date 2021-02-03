#include "iostream"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int first = 0, to_open = 0;
    while(n--){
      char c; cin >> c;
      if(c == '(')
        first++;
      else{
        if(first > 0)
          first--;
        else
          to_open++;
      }
    }
    if(to_open == first && to_open < 2)
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
