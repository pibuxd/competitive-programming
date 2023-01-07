#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m;
vector<int> a, b, x;
vector<bool> ok;

string solve(){
  stack<int> S;
  vector<int> l(n+1, 0), r(n+1, n+1);
  for(int i = 1; i <= n; i++){
    while(!S.empty() && b[S.top()] < b[i]){
      r[S.top()] = i;
      S.pop();
    }
    S.push(i);
  }
  S = stack<int>();
  for(int i = n; i >= 1; i--){
    while(!S.empty() && b[S.top()] < b[i]){
      l[S.top()] = i;
      S.pop();
    }
    S.push(i);
  }
  
  vector<vector<int>> h;
  unordered_map<int, int> raz(n+1);
  h.resize(n+1);
  for(int i = 1; i <= n; i++)
    if(!ok[i])
      h[b[i]].push_back(i);
  for(int i = 1; i <= m; i++)
    raz[x[i]]++;
  
  for(int c = n; c >= 1; c--){
    if(h[c].size() == 0) continue;
    if(!raz[c]) return "NO";
    raz[c]--;
    for(int i = 1; i < h[c].size(); i++){
      if(r[h[c][i-1]] <= l[h[c][i]]){
        if(raz[c] > 0)
          raz[c]--;
        else
          return "NO";
      }
    }
  }
  return "YES";
}

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    cin >> n;
    a.assign(n+1, 0);
    b.assign(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    cin >> m;
    ok.assign(n+1, false);
    x.assign(m+1, 0);
    for(int i = 1; i <= m; i++) cin >> x[i];
    unordered_map<int, int> id;
    vector<int> c = b;
    int nr = 0;
    for(int i = 1; i <= n; i++){
      if(a[i] == b[i]) ok[i] = true;
      else if(a[i] < b[i]){cout << "NO\n"; goto ski; }
    }
    sort(all(c));
    for(int i = 1; i <= n; i++)
      if(id[c[i]] == 0 && c[i] != 0) 
        id[c[i]] = ++nr;
    for(int i = 1; i <= n; i++)
      b[i] = id[b[i]];
    for(int i = 1; i <= m; i++)
      x[i] = id[x[i]];
    cout << solve() << "\n";
ski:;
  }
}
