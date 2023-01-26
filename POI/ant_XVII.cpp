#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int unsigned int
#define ll long long

int n;
int M1 = 1e9+4202137, p1 = 29;
vector<bool> s, sp;
vector<int> h1, hp1, P1;

void initP(vector<int> &P, int M, int p){
  P[0] = 1;
  for(int i = 1; i <= n; i++)
    P[i] = (ll)((ll)P[i-1] * p) % M;
}

void initH(const vector<bool> &s, vector<int> &H, vector<int> &P, int M){
  for(int i = 1; i <= n; i++)
    H[i] = (H[i-1] + P[i]*s[i]) % M;
}

int geth(int l, int r, vector<int> &H, vector<int> &P, int M){
  return ((ll)((H[r] + M - H[l-1]) % M) * P[n-r]) % M;
}

bool check(int x, int st){ // x-len, st-starting pos
  int l = st-x+1, r = st+x;
  int lp = n-r+1, rp = n-l+1;
  return geth(l, r, h1, P1, M1) == geth(lp, rp, hp1, P1, M1);
}

signed main(){
  fastio;
  cin >> n;
  s.resize(n+1);
  h1.resize(n+1);
  hp1.resize(n+1);
  P1.resize(n+1);

  for(int i = 1; i <= n; i++){
    char c; cin >> c;
    s[i] = (c == '1');
  }

  sp = s;
  sp.push_back(0);
  reverse(all(sp));
  for(int i = 1; i <= n; i++)
    sp[i] = !sp[i];

  initP(P1, M1, p1);
  initH(s, h1, P1, M1);
  initH(sp, hp1, P1, M1);
    
  ll sum = 0;
  for(int i = 1; i < n; i++){
    int l = 1, r = min(i, n-i), ans = 0;
    while(l <= r){
      int mid = (l+r)/2;
      if(check(mid, i))
        l = mid+1, ans = mid;
      else
        r = mid-1;
    }
    sum += (ll)ans;
  }

  cout << sum << "\n";
}
