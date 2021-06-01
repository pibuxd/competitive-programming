#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

const int MAXN = 1e9;

int main(){
  fastio;
  map<int, int> brak, istn;

  brak[0] = 1;

  int t;
  cin >> t; 

  while(t--){
    char z;
    cin >> z;

    if(z == '+'){
      int x;
      cin >> x;
      istn[x]++;
      brak.erase(x);
      if(brak.size() == 0){
        for(int i = 0; i <= MAXN; i++){
          if(!istn[i]){
            brak[i] = 1;
            break;
          }
        }
      }
    } else if(z == '-'){
      int x;
      cin >> x;
      istn[x]--;
      if(!istn[x]){
        brak[x] = 1;
      }
    } else{
      map<int, int>::iterator it = brak.begin();
      cout << it->first << "\n";
    }
  }
}