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
  return par[v];
}

void make_set(int a, int b, int w){
  array<int, 2> sa = find_set(a);
  array<int, 2> sb = find_set(b);

  if(sa[0] == sb[0]) return;

  par[b][0] = par[a][0];
}

void solve(){
  par.assign(n+1, array<int, 2>());
  while(m--){
    char c;
    int a, b;
    cin >> c >> a >> b;
    if(c == '!'){
      int w;
      cin >> w;
      make_set(a, b, w);
    }
    else{
      array<int, 2> fa = find_set(a);
      array<int, 2> fb = find_set(b);

      if(fa[0] != fb[0]){
        cout << "UNKNOWN\n";
        continue;
      }
      cout << fb[1] - fa[1];
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