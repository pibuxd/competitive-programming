#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<int> a, b;
vector<bool> ch;
vector<array<int, 3>> tree;
stack<int> changed;

array<int, 3> add(const array<int, 3> &x, const array<int, 3> &y){
  if(!x[2] || !y[2])
    return {x[0], y[1], 0};
  if(a[x[1]] > a[y[0]]){
    if(b[x[1]] <= a[y[0]] && b[x[1]] >= a[x[1]-1] && !ch[x[1]]){
      ch[x[1]] = true;
      swap(a[x[1]], b[x[1]]);
      changed.push(x[1]);
      return {x[0], y[1], 1};

    } else if(a[x[1]] <= b[y[0]] && b[y[0]] <= a[y[0]+1] && !ch[y[0]]){
      ch[y[0]] = true;
      swap(a[y[0]], b[y[0]]);
      changed.push(y[0]);
      return {x[0], y[1], 1};
    }
    return {x[0], y[1], 0};
  }
  return {x[0], y[1], 1};
}

void build(int v = 1, int l = 1, int r = n){
  if(l == r){
    tree[v] = {l, l, 1};
    return;
  }
  int m = (l+r)/2;
  build(2*v, l, m);
  build(2*v+1, m+1, r);
  tree[v] = add(tree[2*v], tree[2*v+1]);
}

void update(int v, int l, int r, int k, int x){
  if(l == r){
    tree[v] = {l, l, 1};
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
  while(!changed.empty()){
    int x = changed.top();
    changed.pop();
    ch[x] = false;
    swap(a[x], b[x]);
  }
  return tree[1][2];
}

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);
  b.resize(n+1);
  ch.resize(n+1);
  for(int i = 1; i <= n; i++)
    cin >> a[i] >> b[i];
  
  tree.resize(4*(n+1));
  cin >> q;
  int _startq = q-1;
  while(q--){
    int x, y;
    cin >> x >> y;
    int _x = a[x], _y = a[y], __x = b[x], __y = b[y];
    a[x] = _y, a[y] = _x, b[x] = __y, b[y] = __x;
    if(q == _startq)
      build();
    else{
      update(1, 1, n, y, _x);
      update(1, 1, n, x, _y);
    }
    /*
    for(int i = 1; i <= n; i++)
      cout << a[i] << " ";
    */
    bool _ans = query();
    if(_ans)
      cout << "TAK ";
    else
      cout << "NIE ";
    /*
    for(int i = 1; i <= n; i++)
      cout << a[i] << " ";
    */
    cout << "\n";
    changed = stack<int>();
  }
}