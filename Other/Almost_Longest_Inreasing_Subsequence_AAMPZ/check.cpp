#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;

  int x, k = 0;
  while(cin >> x){
    if(x == 1) k++;
  }

  cout << k;
}
