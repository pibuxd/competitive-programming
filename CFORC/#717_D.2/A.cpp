#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void solve(long long n, long long k, vector<long long> &a){
  long long s = 0, e = n-1;

  while(k > 0){
    if(!a[s]) s++;
    if(s == e) return;

    int sub = min(k, a[s]);
    a[s] -= sub;
    a[e] += sub;
    k -= sub;
  }
}

int main(){
  fastio;
  long long t;
  cin >> t;

  while(t--){
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for(long long &x : a) cin >> x;
    solve(n, k, a);
    for(long long &x : a) cout << x << " ";
    cout << "\n";
  }
}