#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<int> a;

int lis(){
  vector<int> v;

  for(int i = 1; i <= n; i++){
    auto it = lower_bound(all(v), a[i]);
    if(it == v.end())
      v.push_back(a[i]);
    else
      *it = a[i];
  }

  return v.size();
}

int main(){
  fastio;

  cin >> n;
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  cout << lis();
}
