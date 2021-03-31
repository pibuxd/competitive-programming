#include <bits/stdc++.h>
using namespace std;
 
// segment tree (maximum value)

int n, q;
vector<int> V, Tree;

void initData(){
  cin >> n >> q;
 
  V = vector<int>(n+1);
  Tree = vector<int>(4*(n+1));
 
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

  Tree[v] = max(Tree[2*v], Tree[2*v+1]);
}

void updateTree(int v, int l, int r, int idx, int val){
  if(l == r){
    V[idx] = val;
    Tree[v] = val;
  
  } else{
    int mid = (l + r) / 2;

    if(idx >= l && idx <= mid){
      updateTree(2*v, l, mid, idx, val);
    } else{
      updateTree(2*v+1, mid+1, r, idx, val);
    }

    Tree[v] = max(Tree[2*v], Tree[2*v+1]);
  }
}

int queryOfMaximum(int v, int l, int r, int x, int y){
  if(x > r || l > y){
    return(-(1e9));
  }
  if(x <= l && y >= r){
    return Tree[v];
  }

  int q1, q2, mid;
  mid = (l + r) / 2;
  q1 = queryOfMaximum(2*v, l, mid, x, y);
  q2 = queryOfMaximum(2*v+1, mid+1, r, x, y);

  return(max(q1, q2));
}

void testTree(){
  string operation;
  int a, b;
  
  while(q--){
    cin >> operation;
    cin >> a >> b;
    
    if(operation == "UPDATE")
      updateTree(1, 1, n, a, b);
    else
      cout << queryOfMaximum(1, 1, n, a, b) << '\n';
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  
  while(t--){
    initData(); 
    buildTree(1, 1, n);
    testTree();
  }
}