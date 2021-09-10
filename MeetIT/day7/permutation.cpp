#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> p;

int main(){
  fastio;
  cin >> n;
  p.resize(n+1);
  p[0] = -1;
  for(int i = 1; i <= n; i++) cin >> p[i];

  int ans = 0;

  for(int i = 1; i < n; i++){
    if(p[i] == i && p[i+1] == i+1){
      swap(p[i], p[i+1]);
      ans++;
    }
    if(p[i-1] == i-1){
      ans++;
    }
  }

  if(p[n] == n)
    ans++;
  if(p[n-1] == n-1)
    ans++;

  cout << ans;
}