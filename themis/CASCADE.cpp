#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;

char solve(){
  cin >> n;

  int j = 0;
  
  for(int i = 1; i <= n; i++){
    int x; cin >> x;
    if(x > 1) x = 2;

    if(i == j+1 && x == 1) j++;
  }

  if(j == n && j % 2 == 1) return 'P';
  if(j < n && j % 2 == 0) return 'P';
  return 'D';
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--) cout << solve() << "\n";
}
