#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main(){
  fastio;
  int n, S;
  cin >> n >> S;

  vector<int> a(n+1);
  unordered_map<int, int> ai;

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    ai[a[i]]++;
  }

  for(int i = 1; i <= n; i++){
    if(S-a[i] == a[i] && ai[S-a[i]] >= 2){
      cout << "TAK";
      return 0;
    } else if(S-a[i] != a[i] && ai[S-a[i]] >= 1){
      cout << "TAK";
      return 0;
    }
  }

  cout << "NIE";
}