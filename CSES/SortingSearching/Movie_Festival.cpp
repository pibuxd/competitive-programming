#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<array<int, 2>> v;

int main(){
  fastio;
  cin >> n;
  v.resize(n);

  for(auto &x : v){
    cin >> x[1] >> x[0];
  }

  sort(v.begin(), v.end());
  
  int last = 0, ans = 0;
  for(auto x : v){
    if(last <= x[1]){
      last = x[0];
      ans++;
    }
  }
  
  cout << ans;
}