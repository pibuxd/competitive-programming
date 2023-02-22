#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int mxn = 1e5;
int n, m;
vector<int> par, siz;

int union_find(int v){
  if(par[v] == v) return v;
  return par[v] = union_find(par[v]);
}

void union_make(int a, int b){
  a = union_find(a), b = union_find(b);
  if(a != b){
    if(siz[a] < siz[b])
      swap(a, b);
    siz[a] += siz[b];
    siz[b] = 0;;
    par[b] = a;
  }
}

int main(){
  fastio;
  cin >> n >> m;
  par.resize(n+1);
  siz.resize(n+1);
    
  for(int i = 1; i <= n; i++)
    par[i] = i, siz[i] = 1;

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b;
    union_make(a, b);
  }
  
  bitset<mxn+1> b;
  b[0] = 1;

  for(int i = 1; i <= n; i++){
    if(!siz[i]) continue;
    b |= (b << siz[i]);
  }
  for(int i = 1; i <= n; i++)
    cout << b[i];
  cout << "\n";
}
