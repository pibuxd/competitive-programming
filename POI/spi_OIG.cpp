// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int n, sum = 0, z = 0; cin >> n; char a;
  for(int i = 0; i < n; i++){ cin >> a;
    if(a == 'W'){
      sum += (z / 3);
      if(z % 3 > 0) sum++;
      z = 0;
    }
    if(a == 'Z') z++;
  }
  if(z > 0){
    sum += (z / 3);
    if(z % 3 > 0) sum++;
  }
  cout << sum;
}
