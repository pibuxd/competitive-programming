// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> v;

int main(){
  fastio;
  cin >> n;
  
  int ans = 0;
  while(n--){
    int x;
    cin >> x;

    auto it = upper_bound(v.begin(), v.end(), x);
    if(it == v.end())
      v.push_back(x), ans++;
    else
      *it = x;
  }

  cout << ans;
}