#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<int> a;

vector<int> solve(){
  a.resize(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];
  if(n == 1) return a;
  if(n == 2){
    if(a[1] == a[2]) return {};
    return a;
  }

  a[0] = 1000;
  sort(a.rbegin(), a.rend());
  if(a[1] == a[2]) swap(a[2], a[n]);
  int p = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] == p) return {};
    p += a[i];
  }
  return a;
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    vector<int> s = solve();
    if(s.empty()) cout << "NO";
    else{
      cout << "YES\n";
      for(int i = 1; i <= n; i++) cout << s[i] << " ";
    }
    cout << "\n";
  }
}
