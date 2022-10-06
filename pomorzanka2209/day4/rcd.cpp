#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, mx, subsum;
vector<vector<int>> G;
vector<int> sub, mxsub;

void dfssub(int v, int p){
  sub[v] = 1;
  mxsub[v] = 0;

  for(int x : G[v]){
    if(x == p) continue;
    dfssub(x, v);

    sub[v] += sub[x];
    mxsub[v] = max(mxsub[v], sub[x]);
  }
  subsum += sub[v];
}

void dfsmx(int v, int p){
  //mx = (sub[i]-1-mxs)*mxs + sumsub[i];
  int currmx = (sub[v] - 1 - mxsub[v]) * mxsub[v] + subsum;
  mx = max(mx, currmx);
  
  int sv = sub[v], ss = subsum;

  for(int x : G[v]){
    if(x == p) continue;
    int sx = sub[x], mxsx = mxsub[x];

    sub[x] = n, sub[v] -= sx;
    subsum = subsum - 2*sx + n;
    mxsub[x] = max(mxsub[x], sub[v]);
    
    dfsmx(x, v);

    subsum = ss;
    sub[v] = sv;
    sub[x] = sx;
    mxsub[x] = mxsx;
  }
}

signed main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  sub.resize(n+1, 0);
  mxsub.resize(n+1, 0);

  for(int i = 1; i <= n-1; i++){
    int a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  
  if(n == 1){
    cout << 0 << " " << 0 << "\n";
    return 0;
  }

  mx = subsum = 0;
  dfssub(1, 0);
  subsum -= n;
  dfsmx(1, 0);
    /*
    vector<int> s;
    for(int x : G[i])
      s.push_back(sub[x]);
    int mxs = *max_element(s.begin(), s.end());
    mx = (sub[i]-1-mxs)*mxs + sumsub[i];
    */
  
  cout << n-1 << " " << mx << "\n";
}
