// * Fenwick Tree or BIT (Binary Indexed Tree)
// * RANGE add, POINT query
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<int> tree;

// add x from k to n
void add(int k, int x){
  while(k <= n){
    tree[k] += x;
    k += k &- k;
  }
}

void range_add(int l, int r, int val){
  add(l, val);
  add(r+1, -val);
}

// sum from 1 to k
int query(int k){
  int s = 0;
  while(k > 0){
    s += tree[k];
    k -= k &- k; // get first bit on eg. 10 = 1010 -> 2^1
  }

  return s;
}

int main(){
  fastio;
  cin >> n >> m;
  tree.resize(n+2);
  
  for(int i = 1, p = 0, x; i <= n; i++, p = x){
    cin >> x;
    add(i, x - p);
  }
  while(m--){
    int operation;
    cin >> operation;
    if(operation == 1){
      int a, b, u;
      cin >> a >> b >> u;
      range_add(a, b, u);
    } else{
      int k;
      cin >> k;
      cout << query(k) << "\n";
    }
  }
}