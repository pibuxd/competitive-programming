#include <bits/stdc++.h>
using namespace std;

const int MXN = 2e5;
int n, m;
vector<int> V;
vector<int> Tree;

void initData(){
  cin >> n >> m;
  V = vector<int>(n+1);
  Tree = vector<int>(4*(n+1));
}

void updateTree(int idx, int val, int l = 1, int r = n, int v = 1){
  if(l == r){
    Tree[v] = val;
    return;
  }

  int mid = (l + r) / 2;

  if(idx >= l && idx <= mid){
    updateTree(idx, val, l, mid, 2*v);
  } else{
    updateTree(idx, val, mid+1, r, 2*v+1);
  }

  Tree[v] = max(Tree[2*v], Tree[2*v+1]);
}

void checkTree(int truckLen, int dlg){
  
}

void testInput(){
  while(m--){
    int a, b;
    char oper;

    cin >> oper >> a >> b;

    if(oper == 'U'){
      updateTree(a, b);
    } else{
      checkTree(a, b);
    }
  }
}

int main(){
  initData();
  testInput();
}