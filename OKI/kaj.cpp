#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int w, n;
vector<int> a;

int main(){
  fastio;
  cin >> w >> n;
  a.resize(n+1);
  a[0] = INT_MAX;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a.rbegin(), a.rend());

  int res = 0, l = 1, r = n;
  while(l <= r){
    if(a[l] + a[r] <= w)
      l++, r--;
    else
      l++;
    res++;
  }

  cout << res;
}