#include <bits/stdc++.h>
using namespace std;
 
// segment tree

int n, q;
vector<int> V;
vector<int> Tree;
 
void initData(){
  cin >> n >> q;
 
  V = vector<int>(n+1);
  Tree = vector<int>(4*n);
 
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
  
  Tree[v] = (Tree[2*v]^Tree[2*v+1]);
}
 
int query(int v, int l, int r, int x, int y){
  if(x > r || l > y){
    return 0;
  }
  if(x <= l && y >= r){
    return Tree[v];
  }
 
  int mid, q1, q2;
  mid = (l + r) / 2;
  q1 = query(2*v, l, mid, x, y);
  q2 = query(2*v+1, mid+1, r, x, y);
 
  return((q1^q2));
}
 
int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  initData();
  buildTree(1, 1, n);
 
  while(q--){
    int a, b;
    cin >> a >> b;
    cout << query(1, 1, n, a, b) << '\n';
  }
}