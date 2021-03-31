#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef unsigned long long ull; 

struct Node{
  int value = 0, complement = 0, numberOfChilds = 0, it = 0;
};

int n, m, a, b;
vector<int> V;
vector<Node> tree;

void buildTree(int v = 1, int l = 1, int r = n){
  // TODO: po kolei 

  if(l == r){
    tree[l].value = V[l];
    tree[l].it = l;
    return;
  } 
 
  int mid = (l + r) / 2;
  buildTree(2*v, l, mid);
  buildTree(2*v+1, mid+1, r);
 
  tree[v].value = max(tree[2*v].value, tree[2*v+1].value);
  tree[v].numberOfChilds = 0;

  if(tree[v].numberOfChilds == 0){
    if(tree[2*v].it % 2 == 1 && tree[2*v].value > tree[2*v+1].value){
      tree[v].complement = tree[2*v].value - tree[2*v+1].value;

    } else if(tree[2*v].it % 2 == 0 && tree[2*v].value < tree[2*v+1].value){
      tree[v].complement = tree[2*v+1].value - tree[2*v].value;
    }
  } else{
    tree[v].complement = tree[2*v].complement + (tree[v].value - tree[2*v].value) * tree[2*v].numberOfChilds;
    tree[v].complement = tree[2*v+1].complement + (tree[v].value - tree[2*v+1].value) * tree[2*v+1].numberOfChilds;
  }
}

ull minOfIncr(int v = 1, int l = 1, int r = n){
  return 0;
}

int main(){ fastio;
  cin >> n >> m;
  V = vector<int>(n+1);
  tree = vector<Node>(n+1);
  
  for(int i = 1; i <= n; i++){
    cin >> V[i];
  }
  
  buildTree();
  
  while(m--){
    cin >> a >> b;
    cout << minOfIncr() << '\n';
  }

  cout << '\n';
  for(int i = 1; i <= 2*n; i++){
    cout << tree[i].value << ',' << tree[i].complement << ',' << tree[i].numberOfChilds << ',' << tree[i].it << '\n';
  }
}