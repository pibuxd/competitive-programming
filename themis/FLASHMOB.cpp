#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

struct cycle {
  int len;
  vector<int> kol;
};

int n;
vector<int> a, par, kolodw;
vector<cycle> t;

void dfs(int v, vector<int> &kol, int c, int l){
  par[v] = c;
  kol.push_back(v);
  kolodw[v] = kol.size()-1;

  if(par[a[v]])
    t[c] = {l, kol};
  else
    dfs(a[v], kol, c, l+1);
}

int main(){
  fastio;
  cin >> n;

  a.resize(n+1);
  par.resize(n+1);
  kolodw.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  t.resize(1);
  
  for(int i = 1; i <= n; i++)
    if(!par[i]){
      t.push_back(cycle());
      vector<int> v;
      dfs(i, v, t.size()-1, 1);
    }

  int q; cin >> q;
  while(q--){
    int A, K; cin >> A >> K;
    int Kmod = (K+kolodw[A]+t[par[A]].len) % t[par[A]].len;
    cout << t[par[A]].kol[Kmod] << '\n';
  }
}
