#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ans;
vector<int> a;

int main(){
  fastio;
  cin >> n >> k;
  a.resize(n+1);
  a[0] = INT_MAX;
  
  for(int i = 1; i <= n; i++)
    cin >> a[i];
  sort(a.rbegin(), a.rend());

  ans = k;
  for(int i = k+1; i <= n; i++)
    if(a[i] == a[k])
      ans++;
  
  cout << ans;
}