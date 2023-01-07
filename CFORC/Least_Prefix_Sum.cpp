#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m;
vector<int> a;

int solve(){
  if(n == 1) return 0;
  int res = 0;
  int summ = 0;
  for(int i = 1; i <= m; i++)
    summ += a[i];
  
  int s = summ;
  priority_queue<int> Q, P;
  for(int i = m; i >= 2; i--){
    if(a[i] > 0)
      Q.push(2*a[i]);
    s -= a[i];
    while(s < summ){
      summ -= Q.top();
      Q.pop();
      res++;
    }
  }
  s = 0;
  for(int i = m+1; i <= n; i++){
    if(a[i] < 0)
      P.push(-2*a[i]);
    s += a[i];
    while(s < 0){
      s += P.top();
      P.pop();
      res++;
    }
  }

  return res;
}

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n >> m;
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << solve() << "\n";
  }
}
