// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> factors(int n){
  vector<pair<int, int>> ret;

  for(int i = 2; i * i <= n; i++){
    int cnt = 0;
    while(n % i == 0){
      cnt++;
      n /= i;
    }
    if(cnt)
      ret.push_back({i, cnt});   
  }
  
  if(n > 1)
    ret.push_back({n, 1});

  return ret;
}

int main(){
  int n;
  cin >> n;

  auto fac = factors(n);

  for(auto i : fac)
    cout << i.first << ", " << i.second << "\n";
}