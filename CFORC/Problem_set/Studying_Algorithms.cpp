#include <bits/stdc++.h>
using namespace std;

int x, n;
vector<int> v;

int main(){
  cin >> x >> n;
  v.resize(x);

  for(int &i : v)
    cin >> i;
  
  sort(v.begin(), v.end());

  int _n = 0, ans = 0;
  for(int &i : v){
    if(_n + i > n)
      break;
    _n += i;
    ans++;
  }
  cout << ans;
}