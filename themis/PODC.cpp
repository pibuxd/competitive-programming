#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n;
vector<int> a;

int iloc(int x){
  int ilo = 1;
  while(x > 0){
    ilo *= x % 10;
    x /= 10;
  }
  return ilo;
}

int foo(int x){
  if(x == 0) return 0;
  int res = 0, mn = 1;
  for(int i = 9; i >= 2; i--)
    while(x % i == 0)
      res += i * mn, mn *= 10, x /= i;
  return res;
}

int ok(int x){
  int i = 1;
  while(!a[i]){
    if(iloc(x)) return 0;
    x++, i++;
  }
  if(iloc(x) == 0) return 0;
  if(a[i] % iloc(x)) return 0;
  int pr = a[i] / iloc(x);
  x++, i++;

  while(i <= n){
    if(a[i] != pr * iloc(x)) return 0;
    x++, i++;
  }
  return pr;
}

int solve(){
  cin >> n;
  a.assign(n+1, 0);
  for(int i = 1; i <= n; i++) cin >> a[i];
  if(n == 1 && a[1] == 0) return 10;
  int xx = 1;
  while(xx <= n){
    if(a[xx]) break;
    xx++;
  }
  
  if(n > 1 && xx == n+1 && n <= 11) return 100;
  else if(n > 1 && xx == n+1) return 1000;
  
  int mn = LONG_LONG_MAX;
  for(int i = 10000; i >= 1; i--){
    int g = ok(i);
    if(!g) continue;
    int num = foo(g);
    //cout << i << ": " << num << "\n";
    int c = 0;
    if(i / 1000) c = i+num*10000;
    else if(i / 100) c = i+num*1000;
    else if(i / 10) c = i+num*100;
    else c = i+num*10;
    mn = min(mn, c);
  }
  return mn;
}

signed main(){
  fastio;
  cout << solve() << "\n";
}
