#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, ans;
vector<int> par, in;

void make_set(int v){
  par[v] = v;
}

int find_set(int v){
  if(par[v] == v)
    return v;
  return par[v] = find_set(par[v]);
}

void set_unions(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a != b)
    par[b] = a;
}

int main(){
  fastio;
  cin >> n >> m;
  par.resize(n+1);
  in.resize(n+1);
  ans = 0;

  for(int i = 1; i <= n; i++){
    cin >> in[i];
    make_set(i);
  }

  for(int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    set_unions(a, b);
  }

  for(int i = 1; i <= n; i++){
    int now = find_set(i);
    int go = find_set(in[i]);

    if(now == go){
      ans++;
    }
  }

  cout << ans << "\n";
}