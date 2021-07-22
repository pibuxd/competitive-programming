// 30% -> a[i] = b[i]
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<int> a, b;
vector<array<int, 3>> tree;

array<int, 3> add(const array<int, 3> &a, const array<int, 3> &b){
  int can = 1;
  if(!a[2] || !b[2] || a[1] > b[0])
    can = 0;
  return {a[0], b[1], can};
}

void build(int v = 1, int l = 1, int r = n){
  if(l == r){
    tree[v] = {a[l], a[l], 1};
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = add(tree[2*v], tree[2*v+1]);
}

void update(int v, int l, int r, int k, int x){
  if(l == r){
    tree[v] = {a[l], a[l], 1};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    update(2*v, l, m, k, x);
  else
    update(2*v+1, m+1, r, k, x);
  tree[v] = add(tree[2*v] , tree[2*v+1]);
}

bool query(){
  return tree[1][2];
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  b.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  
  tree.resize(4*(n+1));
  build();
  cin >> q;
  while(q--){
    int x, y;
    cin >> x >> y;
    int _x = a[x], _y = a[y];
    a[x] = _y, a[y] = _x;
    update(1, 1, n, y, _x);
    update(1, 1, n, x, _y);
    //for(int i = 1; i <= n; i++)
      //cout << a[i] << " ";
    
    bool _ans = query();
    if(_ans)
      cout << "TAK\n";
    else
      cout << "NIE\n"; 
  }
}