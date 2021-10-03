#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ans, INF = 1e9;
vector<int> d;

void fill_start(int l, set<array<int, 2>> &S){
  for(int i = l+1; i <= k+l && i <= n; i++){
    S.insert({d[i], i});
  }
}

void jump(int &l, set<array<int, 2>> &S){
 
  

}

void solve(){
  
}

int main(){
  fastio;
  cin >> n;
  d.assign(n+1, 0);

  for(int i = 1; i <= n; i++){
    cin >> d[i];
  }

  int q;
  cin >> q;
  while(q--){
    cin >> k;
    solve();
    cout << ans << "\n";
  }
}