#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define m (l+r)/2 // mid
#define lv 2*v // left vertex
#define rv 2*v+1 // right vertex

struct Node {
  int val = 0, lz = 0;
};

int n, q;
vector<Node> tree;

void push_down(int v){
  if(tree[v].lz == 0)
    return;
  tree[lv].val = tree[rv].val = tree[lv].lz = tree[rv].lz = tree[v].lz;
  tree[v].lz = 0;
}

void push_up(int v){
  tree[v].val = max(tree[lv].val, tree[rv].val);
}

void update(int v, int l, int r, int a, int b, int x){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v].val = x;
    tree[v].lz = x;
    return;
  }

  push_down(v);
  update(lv, l, m, a, b, x);
  update(rv, m+1, r, a, b, x);
  push_up(v);
}

int query(int v, int l, int r, int a, int b){
  if(l > b || r < a)
    return 0;
  if(a <= l && r <= b)
    return tree[v].val;

  push_down(v);
  return max(query(lv, l, m, a, b), query(rv, m+1, r, a, b));
}

int main(){
  fastio;
  cin >> n >> q;
  n++;
  tree.resize(1<<21);

  while(q--){
    int a, b;
    cin >> a >> b;
    b++;
    if(a == 0) continue;

    int x = query(1, 1, n, b, b+a-1);
    update(1, 1, n, b, b+a-1, x+1);
  }

  cout << tree[1].val << "\n";
}