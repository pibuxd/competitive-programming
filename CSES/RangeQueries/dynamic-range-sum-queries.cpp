#include <bits/stdc++.h>
using namespace std;
 
// segment tree

typedef unsigned long long ull; 

int n, q;
vector<ull> Tree;
vector<int> V;

void initData(){
  cin >> n >> q;
 
  V = vector<int>(n+1);
  Tree = vector<ull>(4*n);
 
  for(int i = 1; i <= n; i++){
    cin >> V[i];
  }
}

void buildTree(int v, int l, int r){
  if(l == r){
    Tree[v] = V[l];
    return;
  } 

  int mid = (l + r) / 2;
  buildTree(2*v, l, mid);
  buildTree(2*v+1, mid+1, r);

  Tree[v] = Tree[2*v] + Tree[2*v+1];
}

void updateTree(int v, int l, int r, int idx, int val){
  if(idx < l || idx > r){
    return;
  }

  if(l == r){
    V[idx] = val;
    Tree[v] = val;
    
  } else{
    int mid = (l + r) / 2;
    updateTree(2*v, l, mid, idx, val);
    updateTree(2*v+1, mid+1, r, idx, val);

    Tree[v] = Tree[2*v] + Tree[2*v+1];
  }
}

ull queryOfSum(int v, int l, int r, int x){
  if(x > r || l > y){
    return 0;
  }
  if(x <= l && y >= r){
    return Tree[v];
  }

  int mid;
  mid = (l + r) / 2;
  ull q1, q2;
  q1 = queryOfSum(2*v, l, mid, x, y);
  q2 = queryOfSum(2*v+1, mid+1, r, x, y);

  return(q1 + q2);
}

void testTree(){
  int operation, x, a, b, u;
  
  while(q--){
    cin >> operation;
    
    if(operation == 1){
      cin >> a >> b >> u;
      updateTree(1, 1, n, a, b);
    }
    else{
      cin >> x;
      cout << queryOfSum(1, 1, n, x) << '\n';
    }
  } 
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  initData();
  buildTree(1, 1, n);
  testTree();
}