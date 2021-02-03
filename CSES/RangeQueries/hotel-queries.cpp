#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5;
int n, m;
vector<int> V;
vector<int> Tree;

void buildTree(int v = 1, int l = 1, int r = n){
  if(l == r){
    Tree[v] = V[l];
    return;
  }

  int mid = (l + r) / 2;
  
  buildTree(2*v, l, mid);
  buildTree(2*v+1, mid + 1, r);

  Tree[v] = max(Tree[2*v], Tree[2*v+1]);
}

void initData(){
  cin >> n >> m;
  V = vector<int>(n+1);
  Tree = vector<int>(4*(n+1));

  for(int i = 1; i <= n; i++){
    cin >> V[i];
  }

  buildTree();
}

void updateTree(int val, int l = 1, int r = n, int v = 1){
  if(l == r){
    Tree[v] -= val;
    cout << l << ' ';
    return;
  }

  int mid = (l + r) / 2;

  if(Tree[2*v] >= val){
    updateTree(val, l, mid, 2*v);
  } else{
    updateTree(val, mid+1, r, 2*v+1);
  }

  Tree[v] = max(Tree[2*v], Tree[2*v+1]);
}

void testInput(){
  while(m--){
    int x;
    cin >> x;

    if(Tree[1] < x){
      cout << "0 ";
    } else{
      updateTree(x);
    }
  }
}

int main(){
  initData();
  testInput();
}