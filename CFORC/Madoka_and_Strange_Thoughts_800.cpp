#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n;

signed main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    cout << n+(2*(n/2))+(2*(n/3)) << "\n";
  }
}
