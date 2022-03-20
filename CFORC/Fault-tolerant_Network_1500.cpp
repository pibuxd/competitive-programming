#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define MX (int)(1e9+20)

int solve(int n){
  vector<int> a(n+1), b(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];

  if(n == 1) return abs(a[1] - b[1]);

  int ans = abs(a[1]-b[n]) + abs(a[n]-b[1]);
  int ans1 = abs(a[1]-b[1]) + abs(a[n]-b[n]);
  int ans2 = 0, ans3 = 0, ans4 = 0, ans5 = 0, ans6 = 0;

  int mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[1]-b[i]));
  ans2 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[n]-b[i]));
  ans2 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[1]));
  ans2 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[n]));
  ans2 += mn;
  
  ans3 += abs(a[1]-b[1]);
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[n]-b[i]));
  ans3 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[n]));
  ans3 += mn;

  ans4 += abs(a[1]-b[n]);
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[n]-b[i]));
  ans4 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[1]));
  ans4 += mn;

  ans5 += abs(a[n]-b[1]);
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[1]-b[i]));
  ans5 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[n]));
  ans5 += mn;

  ans6 += abs(a[n]-b[n]);
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[1]-b[i]));
  ans6 += mn;
  mn = MX, mni = 0;
  for(int i = 1; i <= n; i++)
    mn = min(mn, abs(a[i]-b[1]));
  ans6 += mn;

  return min({ans, ans1, ans2, ans3, ans4, ans5, ans6});
}

signed main(){
  fastio;
  int t; cin >> t;

  while(t--){
    int n; cin >> n;
    cout << solve(n) << "\n";
  }
}