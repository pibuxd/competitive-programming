// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<array<int, 2>> par;

void make_set(int v){
  par[v] = {v, 0};
}

void compress(int v){
  if(par[v][0] == v)
    return;
  
  compress(par[v][0]);

  par[v][0] = par[par[v][0]][0];
  par[v][1] += par[par[v][0]][1];
}

array<int, 2> find_set(int v){
  compress(v);
  if(par[v][0] == v) return par[v];
  return find_set(par[v][0]);
}

void union_sets(int a, int b, int w){
  array<int, 2> sa = find_set(a);
  array<int, 2> sb = find_set(b);

  if(sa[0] == sb[0]) return;

  cout << "b: " << b << " " << par[b][0] << " = " << a << " a: " << a << "\n";
  par[sb[0]][0] = sa[0];
  par[b][1] = w + par[a][1] - par[b][1];
}

void solve(){
  par.assign(n+1, array<int, 2>());
  
  for(int i = 1; i <= n; i++)
    make_set(i);

  while(m--){
    char c;
    int a, b;
    cin >> c >> a >> b;
    if(c == '!'){
      int w;
      cin >> w;
      union_sets(a, b, w);
    }
    else{
      array<int, 2> fa = find_set(a);
      array<int, 2> fb = find_set(b);

      if(fa[0] != fb[0]){
        cout << "UNKNOWN\n";
        continue;
      }
      cout << par[b][1] - par[a][1] << "\n";
    }
  }

}

int main(){
  fastio;
  while(cin >> n >> m){
    if(n == 0 && m == 0) return 0;
    solve();
  }
}