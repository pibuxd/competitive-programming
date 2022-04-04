// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * stack Nearest Element + binary jumping + sparse table
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define INF (m+1)

int n, m, q, LOG;
vector<int> a, p, it;
vector<vector<int>> up, sp;
map<int, int> M;

#define nxt(i) (it[i] < n ? p[it[i]+1] : p[1])
#define bef(i) (it[i] > 1 ? p[it[i]-1] : p[n])

int jump(int v, int k){
  for(int i = 0; i <= LOG; i++)
    if((1 << i) & k){
      v = up[v][i];
      if(!v)
        return INF;
    }
  
  return v;
}

int getmin(int l, int r){
  int len = r-l+1;
  int f = floor(log2(len));
  return min(sp[l][f], sp[r-(1<<f)+1][f]);
}

int main(){
  fastio;
  cin >> n >> m >> q;

  LOG = ceil(log2(m));
  a.resize(m+1);
  p.resize(n+1);
  it.resize(n+1);
  up.resize(m+1, vector<int>(LOG+1));
  sp.resize(m+1, vector<int>(LOG+1));

  for(int i = 1; i <= n; i++){
    cin >> p[i];
    it[p[i]] = i;
  }
  
  for(int i = 1; i <= m; i++) cin >> a[i];
  
  vector<stack<int>> s(n+1);
  for(int i = 1; i <= m; i++){
    while(!s[bef(a[i])].empty()){
      up[s[bef(a[i])].top()][0] = i;
      s[bef(a[i])].pop();
    }
    s[a[i]].push(i);
  }

  for(int i = 1; i <= LOG; i++)
    for(int v = 1; v <= m; v++)
      up[v][i] = up[up[v][i-1]][i-1];

  for(int i = 1; i <= m; i++)
    sp[i][0] = jump(i, n-1);
  
  for(int i = 1; i <= LOG; i++)
    for(int j = 1; j+(1<<(i-1)) <= m; j++)
      sp[j][i] = min(sp[j][i-1], sp[j+(1<<(i-1))][i-1]);

  while(q--){
    int l, r;
    cin >> l >> r;
    int mn = getmin(l, r);
    if(mn <= r)
      cout << '1';
    else
      cout << '0';
  }

}