#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int n; cin >> n;
    vector<int> a(n);

    for(int &x : a) cin >> x;
    sort(a.begin(), a.end());

    int res = 0;
    for(int x : a){
      if(x == a[0]) res++;
    }

    cout << n - res << "\n";
  }
}