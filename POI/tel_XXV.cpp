#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Maszt {
  int s = 0, a = 0;
};

struct Tree {
  int n;
  vector<int> maszty, tree;

  Tree(int _n){
    n = _n;
    maszty.resize(n+1);
    tree.resize(2*n+5);
  }

  void insert(int v, int l, int r, int idx, int val){
    if(idx < l || idx > r){
      return;
    }
  
    if(l == r){
      maszty[idx] = val;
      tree[v] = val;
    
    } else{
      int mid = (l + r) / 2;
      insert(2*v, l, mid, idx, val);
      insert(2*v+1, mid+1, r, idx, val);
  
      tree[v] = tree[2*v] + tree[2*v+1];
    }
  }

  int query(int v, int l, int r, int x, int y){
    if(x > r || l > y){
      return 0;
    }
    if(x <= l && y >= r){
      return tree[v];
    }
  
    int mid;
    mid = (l + r) / 2;
    int q1, q2;
    q1 = query(2*v, l, mid, x, y);
    q2 = query(2*v+1, mid+1, r, x, y);
  
    return(q1 + q2);
  }
};

int main(){
  fastio;
  int n, m, x, s, a, x1, x2; // x1 <= x2
  char operation;
  cin >> n >> m;

  Tree tree(n);
  vector<Maszt> maszty(n+1);

  while(m--){
    cin >> operation;

    if(operation == 'P'){
      cin >> x >> s >> a;
      maszty[x] = {s, a};

      for(int i = x; i <= n; i++){
        if(s <= (i-x) * a) break;

        tree.insert(1, 1, n, i, s-(i-x)*a);
      }

      for(int i = x-1; i > 0; i--){
        if(s <= (x-i) * a) break;

        tree.insert(1, 1, n, i, s-(x-i)*a);
      } 
    } else if(operation == 'U'){
      cin >> x;

    } else{ // Z
      cin >> x1 >> x2;

      int sum = tree.query(1, 1, n, x1, x2);
      cout << sum / (x2-x1+1) << '\n';
    }
  }
}