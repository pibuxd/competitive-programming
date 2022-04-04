// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * using Nearest Smaller Element problem
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> v, l, r;

int main(){
  fastio;
  cin >> n;
  v.resize(n+1);
  l.resize(n+1);
  r.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> v[i];

  stack<int> S;
  S.push(n);
  for(int i = n-1; i >= 1; i--){
    while(!S.empty()){
      int x = S.top();
      if(v[i] < v[x]){
        S.pop();
        l[x] = i;
      }
      else
        break;
    }
    S.push(i);
  }

  S = stack<int>();
  S.push(1);
  for(int i = 2; i <= n; i++){
    while(!S.empty()){
      int x = S.top();
      if(v[i] < v[x]){
        S.pop();
        r[x] = i;
      }
      else
        break;
    }
    S.push(i);
  }

  long long ans = 0;
  for(int i = 1; i <= n; i++){
    long long area = 1;
    area += i - l[i] - 1;
    
    if(r[i])
      area += r[i] - i - 1;
    
    else
      area += n - i;
    
    area *= v[i];
    ans = max(ans, area);
  }

  cout << ans;
}