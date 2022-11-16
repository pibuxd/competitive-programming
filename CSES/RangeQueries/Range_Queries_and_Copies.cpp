#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define m ((l+r)/2)
#define int long long

struct Node {
  int V;
  Node *L;
  Node *R;
  Node(int _V = 0){
    V = _V;
    L = NULL, R = NULL;
  }
};

int n, q;
vector<int> tab;
vector<Node*> arrays;

void build(Node *v, int l = 1, int r = n){
  if(l == r){
    v->V = tab[l];
    return;
  }
  v->L = new Node(), v->R = new Node();
  build(v->L, l, m), build(v->R, m+1, r);
  v->V = v->L->V + v->R->V;
}

Node* settree(Node *v, int l, int r, int idx, int val){
  if(l == r) return new Node(val);
  Node *node = new Node();

  if(idx <= m){
    node->R = v->R;
    if(v->L == NULL) v->L = new Node();
    node->L = settree(v->L, l, m, idx, val);

  } else{
    node->L = v->L;
    if(v->R == NULL) v->R = new Node();
    node->R = settree(v->R, m+1, r, idx, val);
  }
  node->V = 0;
  if(node->R != NULL) node->V += node->R->V;
  if(node->L != NULL) node->V += node->L->V;
  return node;
}

int sumtree(Node *v, int l, int r, int a, int b){
  if(l > b || r < a) return 0;
  if(a <= l && r <= b) return v->V;
  int res = 0;
  if(v->L != NULL) res += sumtree(v->L, l, m, a, b);
  if(v->R != NULL) res += sumtree(v->R, m+1, r, a, b);
  return res;
}

int suminarr(int k, int a, int b){
  return sumtree(arrays[k-1], 1, n, a, b);
}

void setinarr(int k, int a, int x){
  arrays[k-1] = settree(arrays[k-1], 1, n, a, x);
}

void copyarr(int k){
  Node *tree = new Node();
  tree = arrays[k-1];
  arrays.push_back(tree);
}

signed main(){
  fastio;
  cin >> n >> q;
  
  tab.resize(n+1);
  for(int i = 1; i <= n; i++) 
    cin >> tab[i];
  Node *tree = new Node();
  build(tree);
  
  arrays.push_back(tree);
  
  while(q--){
    int op; cin >> op;
    if(op == 1){
      int k, a, x; cin >> k >> a >> x;
      setinarr(k, a, x);

    } else if(op == 2){
      int k, a, b; cin >> k >> a >> b;
      cout << suminarr(k, a, b) << "\n";

    } else{
      int k; cin >> k;
      copyarr(k);
    }
  }
}
