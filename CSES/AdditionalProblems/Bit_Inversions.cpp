// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Segment tree PURQ (point update range query)
// https://usaco.guide/problems/cses-1188-bit-inversions/solution
// We have to do two segment trees (one for th 0s and one for the 1s):

// The longest prefix of 1s in the range [l, r] (denote this as P)
// The longest suffix of 1s in the range [l, r] (denote this as S)
// The longest subarray of 1s in the range [l, r] (denote this as A)
// The length of the subarray (equivalent to r - l + 1) (denote this as L)

// To merge left child a and right child b to make node c

// If a.P = a.L, then c.P = a.L + b.P; otherwise, c.P = a.P
// If b.S = b.L, then c.S = b.L + a.S; otherwise, c.S = b.S
// c.A = max(a.A, b.A, a.S + b.P)
// c.L = a.L + b.L
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Node{
  int p, s, a, l;
};

const int INF = INT_MAX;
int n, q;
vector<Node> tree1, tree0;
vector<bool> a;

void build1(int v = 1, int l = 1, int r = n){
  if(l == r){
    int temp = 0;
    if(a[l]) temp = 1;
    tree1[v] = {temp, temp, temp, 1};
    return;
  }
  int m = (l+r)/2;
  build1(2*v, l, m);
  build1(2*v+1, m+1, r);

  if(tree1[2*v].p == tree1[2*v].l)
    tree1[v].p = tree1[2*v].l + tree1[2*v+1].p;
  else
    tree1[v].p = tree1[2*v].p;

  if(tree1[2*v+1].s == tree1[2*v].l)
    tree1[v].s = tree1[2*v+1].l + tree1[2*v].s;
  else
    tree1[v].s = tree1[2*v+1].s;

  tree1[v].a = max(max(tree1[2*v].a, tree1[2*v+1].a), tree1[2*v].s + tree1[2*v+1].p);
  tree1[v].l = tree1[2*v].l + tree1[2*v+1].l;
}

void build0(int v = 1, int l = 1, int r = n){
  if(l == r){
    int temp = 0;
    if(!a[l]) temp = 1;
    tree0[v] = {temp, temp, temp, 1};
    return;
  }
  int m = (l+r)/2;
  build0(2*v, l, m);
  build0(2*v+1, m+1, r);

  if(tree0[2*v].p == tree0[2*v].l)
    tree0[v].p = tree0[2*v].l + tree0[2*v+1].p;
  else
    tree0[v].p = tree0[2*v].p;

  if(tree0[2*v+1].s == tree0[2*v].l)
    tree0[v].s = tree0[2*v+1].l + tree0[2*v].s;
  else
    tree0[v].s = tree0[2*v+1].s;

  tree0[v].a = max(max(tree0[2*v].a, tree0[2*v+1].a), tree0[2*v].s + tree0[2*v+1].p);
  tree0[v].l = tree0[2*v].l + tree0[2*v+1].l;
}

void build(){
  tree1.resize(4*(n+1), {0, 0, 0, 0});
  tree0.resize(4*(n+1), {0, 0, 0, 0});
  build1();
  build0();
}

void update1(int v, int l, int r, int k){
  if(l == r){
    int temp = 0;
    if(a[l]) temp = 1;
    tree1[v] = {temp, temp, temp, 1};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    update1(2*v, l, m, k);
  else
    update1(2*v+1, m+1, r, k);
  
  if(tree1[2*v].p == tree1[2*v].l)
    tree1[v].p = tree1[2*v].l + tree1[2*v+1].p;
  else
    tree1[v].p = tree1[2*v].p;

  if(tree1[2*v+1].s == tree1[2*v].l)
    tree1[v].s = tree1[2*v+1].l + tree1[2*v].s;
  else
    tree1[v].s = tree1[2*v+1].s;

  tree1[v].a = max(max(tree1[2*v].a, tree1[2*v+1].a), tree1[2*v].s + tree1[2*v+1].p);
  tree1[v].l = tree1[2*v].l + tree1[2*v+1].l;
}

void update0(int v, int l, int r, int k){
  if(l == r){
    int temp = 0;
    if(!a[l]) temp = 1;
    tree0[v] = {temp, temp, temp, 1};
    return;
  }
  int m = (l+r)/2;
  if(k <= m)
    update0(2*v, l, m, k);
  else
    update0(2*v+1, m+1, r, k);
  
  if(tree0[2*v].p == tree0[2*v].l)
    tree0[v].p = tree0[2*v].l + tree0[2*v+1].p;
  else
    tree0[v].p = tree0[2*v].p;

  if(tree0[2*v+1].s == tree0[2*v+1].l)
    tree0[v].s = tree0[2*v+1].l + tree0[2*v].s;
  else
    tree0[v].s = tree0[2*v+1].s;

  tree0[v].a = max(max(tree0[2*v].a, tree0[2*v+1].a), tree0[2*v].s + tree0[2*v+1].p);
  tree0[v].l = tree0[2*v].l + tree0[2*v+1].l;
}

void update(int k){
  a[k].flip();
  update1(1, 1, n, k);
  update0(1, 1, n, k);
}

int query(){
  return max(tree1[1].a, tree0[1].a);
}

int main(){
  fastio;
  string s;
  cin >> s;
  n = s.size();
  a.resize(n+1);
  for(int i = 1; i <= n; i++)
    a[i] = 1 ? s[i-1] == '1' : 0;
  
  build();
  cin >> q;
  while(q--){
    int x;
    cin >> x;
    update(x);
    cout << query() << " ";
  }
}