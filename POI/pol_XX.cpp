#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, cent;
vector<vector<int>> G;
vector<int> sub, subsum;

int dfs(int v, int p){
  sub[v] = 1;
  bool iscent = true;

  for(int x : G[v]){
    if(x == p) continue;
    int d = dfs(x, v);
    if(d) return d;
    
    sub[v] += sub[x];
    if(sub[x] > n/2)
      iscent = false;
  }
  if(iscent && n-sub[v] <= n/2)
    return v;
  return 0;
}

void dfsdp(int v, int p){
  sub[v] = 1;
  for(int x : G[v]){
    if(x == p) continue;
    dfsdp(x, v);
    sub[v] += sub[x];
    subsum[v] += subsum[x] + sub[x];
  }
}

vector<int> calcplecak(){
  vector<int> licz(n, 0), plecak(n, -1);

  for(int x : G[cent])
    licz[sub[x]]++;

  plecak[0] = 0;
  // 2, 3 3, 4
  // 0 1 2 3 4 5 6 7 8 9 0 1 2
  // 0 - - - - - - - - - - - -
  // 0 - 1 - - - - - - - - - -
  // 0 - 0 1 - 1 1 - - - - - -
  // 0 - 0 0 1 - 1 1 - - - - -
  //
  // 1 1 1, 3
  // 0 1 2 3 4 5 6
  // 0 - - - - - -
  // 0 1 2 3 - - -
  // 0 0 0 0
  for(int k = 1; k <= n-1; k++){ // O(sqrt(n))
    if(licz[k] == 0) continue;
    
    for(int i = k; i <= n-1; i++)
      if(plecak[i] == -1 && plecak[i-k] != -1 && plecak[i-k] < licz[k])
        plecak[i] = plecak[i-k] + 1;

    for(int i = k; i <= n-1; i++)
      if(plecak[i] > 0)
        plecak[i] = 0;
  }
  return plecak;
}

signed main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  sub.resize(n+1);
  subsum.resize(n+1);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  cent = dfs(1, 0);
  dfsdp(cent, 0);
  
  vector<int> plecak = calcplecak();

  int a, b, mx = 0;
  for(int i = 0; i <= n-1; i++){
    if(plecak[i] == -1)
      continue;
    if(mx < (n-1-i)*i)
      mx = (n-1-i)*i, a = i, b = n-1-i;
  }

  int ans = mx;
  for(int x : G[cent])
    ans += subsum[x];

  cout << n-1 << " " << ans+n-1 << "\n";
}
