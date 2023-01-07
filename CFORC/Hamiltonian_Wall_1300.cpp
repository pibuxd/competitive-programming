#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<vector<char>> s;

string solve(){
  int p = -1;
  for(int i = 1; i <= n; i++)
    if(s[0][i] != s[1][i])
      p = i;
  if(p == -1) return "YES";

  int k = (s[0][p] == 'B' ? 0 : 1);
  bool o = true;
  for(int i = p; i <= n; i++){
    if(s[k][i] == 'W') o = false;
    if(s[k^1][i] == 'B') k ^= 1;
  }

  k = (s[0][p] == 'B' ? 0 : 1);
  for(int i = p-1; i >= 1; i--){
    if(s[k][i] == 'W') o = false;
    if(s[k^1][i] == 'B') k ^= 1;
  }
  return (o ? "YES" : "NO");
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    s.assign(2, vector<char>(n+1, 0));
    for(int i = 1; i <= n; i++) cin >> s[0][i];
    for(int i = 1; i <= n; i++) cin >> s[1][i];
    cout << solve() << "\n";
  }
}
