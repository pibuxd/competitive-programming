// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Binary search
// * upper bound
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int _upper_bound(int x){
  int l = 0, r = n-1;

  while(l <= r){
    int m = (l+r)/2;

    if(a[m] > x)
      r = m - 1;
    else
      l = m + 1;
  }

  return l;
}

int main(){
  cin >> n >> m;
  a.resize(n);

  for(int &x : a)
    cin >> x;
  
  sort(a.begin(), a.end());

  while(m--){
    int input;
    cin >> input;

    int ub = _upper_bound(input);
    cout << "Upper bound = " << ub << ": " << a[ub] << "\n";
  }
}