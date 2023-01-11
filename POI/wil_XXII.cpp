#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, p, d;
vector<int> w, pref;
deque<int> Q;

void qpush(int val){
  while(!Q.empty() && Q.back() < val)
    Q.pop_back();
  Q.push_back(val);
}

void qpop(int val){
  if(!Q.empty() && Q.front() == val)
    Q.pop_front();
}

int qmax(){
  return Q.front();
}

int s(int a, int b){
  return pref[b] - pref[a-1];
}

signed main(){
  fastio;
  cin >> n >> p >> d;
  w.resize(n + 1);
  pref.resize(n + 1);
  
  for(int i = 1; i <= n; i++){
    cin >> w[i];
    pref[i] = pref[i-1] + w[i];
  }
  
  int l = 1, r = d, ans = d;
  qpush(s(1, d));

  while(l <= n){
    while(s(l, r) - qmax() > p){
      qpop(s(l, l+d-1));
      l++;
    }
    ans = max(ans, r-l+1);
    if(r == n) break;
    r++;
    qpush(s(r-d+1, r));
  }
  cout << ans << "\n";
}
