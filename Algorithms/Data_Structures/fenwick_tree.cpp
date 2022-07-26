// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Fenwick Tree or BIT (Binary Indexed Tree)
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> bit;

void add(int k, int x){
  for(; k <= n; k += k & (-k))
    bit[k] += x;
}

// range add
// when i use range add sum() becomes point query otherwise sum() is 1 -> k query
void add(int l, int r, int val){
  add(l, val);
  add(r+1, -val);
}

// sum from 1 to k or point query if use range add
int sum(int k){
  int s = 0;
  for(; k > 0; k -= k & (-k))
    s += bit[k];
  return s;
}
