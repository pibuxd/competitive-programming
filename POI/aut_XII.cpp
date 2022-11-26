#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lv (2*v)
#define rv (2*v+1)
#define mid ((l+r)/2)

int n, m, k, Q, INF = 1e9+1;
unordered_map<int, int> id;
vector<int> ind, w, xv, yv, tree;
vector<array<int, 3>> p;

void add(int v, int l, int r, int val, int idx){
  if(l == r){
    tree[v] = val;
    return;
  }
  if(idx <= mid) add(lv, l, mid, val, idx);
  else add(rv, mid+1, r, val, idx);
  tree[v] = max(tree[lv], tree[rv]);
}

int qry(int v, int l, int r, int a, int b){
  if(l > b || r < a) return 0;
  if(a <= l && r <= b) return tree[v];

  return max(qry(lv, l, mid, a, b), qry(rv, mid+1, r, a, b));
}

signed main(){
  fastio;
  cin >> n >> m >> k;
  
  w.resize(k+1);
  xv.resize(k+1);
  yv.resize(k+1);
  yv[0] = INF;
  ind.resize(k+1);
  p.resize(k);

  vector<int> S;
  for(int i = 1; i <= k; i++){
    cin >> xv[i] >> yv[i] >> w[i];
    p[i-1] = {yv[i], xv[i], i};
    S.push_back(xv[i]);
  }
  Q = 0;
  sort(S.begin(), S.end());
  int last = 0;
  for(auto s : S) 
    if(s != last)
      id[s] = ++Q, last = s;
  tree.resize(2*(1<<(int)ceil(log2(Q)))+1);
  sort(p.rbegin(), p.rend());

  for(auto P : p){
    int y = P[0], x = id[P[1]], i = P[2];
    //cout << "P: " << y << ", " << x << ", " << i << ", " << w[i] << "\n";
    
    int sum = qry(1, 1, Q, x, Q) + w[i];
    add(1, 1, Q, sum, x);
  }
  
  cout << tree[1] << "\n";
}
