// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<int> a;
vector<vector<bool>> dp;
vector<bool> ans;

int main(){
  fastio;
  cin >> n >> k;
  a.resize(n+1);
  dp.resize(k+1, vector<bool>(n+1));
  ans.resize(k+1, 0);

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    ans[a[i]] = 1;
  }

  for(int i = 1; i <= k; i++){
    for(int j = 1; j <= n; j++){
      if(i-a[j] >= 0)
        ans[i] = ans[i] || !ans[i-a[j]];
    }
  }

  if(ans[k])
    cout << "First";
  else
    cout << "Second";
}