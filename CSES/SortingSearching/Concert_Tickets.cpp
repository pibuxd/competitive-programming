// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n, m;
  cin >> n >> m;
  multiset<int> S;

  while(n--){
    int x;
    cin >> x;
    S.insert(-x);
  }

  while(m--){
    int x;
    cin >> x;
    auto it = S.lower_bound(-x);

    int _ans = -*it;
    if(it == S.end())
      _ans = -1;
    else
      S.erase(it);
    
    cout << _ans << "\n";
  }
}