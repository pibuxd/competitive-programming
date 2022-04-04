// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, INF = 1e17;
vector<int> a, b;


signed main(){
  fastio;
  cin >> n;

  a.resize(n+1);
  b.resize(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];

  int sum = 0;

  for(int i = 1; i <= n; i++){
    sum += abs(a[i] - b[i]);
  }  

  cout << sum << "\n";
  for(int i = 1; i <= n; i++) cout << i << " ";
}