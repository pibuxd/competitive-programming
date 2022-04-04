// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;
  vector<int> v;

  for(int i = 0; i < n; i++){
    int a;
    cin >> a;

    int p = lower_bound(v.begin(), v.end(), a) - v.begin();
    if(p < v.size())
      v[p] = a;
    else
      v.push_back(a);
  }

  cout << v.size();
}