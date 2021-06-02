#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MAXN = 1e9;

int main(){
  fastio;
  map<int, int> istn;
  map<int, bool> brak;

  int t;
  cin >> t; 

  for(int i = 0; i < t; i++){
    brak[i] = 1;
  }
  
  while(t--){
    char z;
    cin >> z;

    if(z == '+'){
      int x;
      cin >> x;
      istn[x]++;
      brak.erase(x);      
    } else if(z == '-'){
      int x;
      cin >> x;
      istn[x]--;
      if(!istn[x]){
        brak[x] = 1;
      }
    } else{
      map<int, bool>::iterator it = brak.begin();
      cout << it->first << "\n";
    }
  }
}

// 0