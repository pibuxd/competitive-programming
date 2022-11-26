#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int n;
ll ans;

struct Node {
  Node* left = NULL;
  Node* right = NULL;
  int size = 0;
};

void add(Node* node, int l, int r, int x){
  if(l == r){
    node->size = 1;
    return;
  }
  int m = (l+r)/2;
  if(x <= m){
    if(node->left == NULL)
      node->left = new Node();
    add(node->left, l, m, x);

  } else{
    if(node->right == NULL)
      node->right = new Node();
    add(node->right, m+1, r, x);
  }
  
  node->size = 0;
  if(node->left != NULL)
    node->size += node->left->size;
  if(node->right != NULL) 
    node->size += node->right->size;
}

int qry(Node* node, int l, int r, int x){ // liczba elementow na przedziale [1, x]
  if(l > x)
    return 0;
  if(r <= x)
    return node->size;

  int m = (l+r)/2;
  int q = 0;
  if(node->left != NULL)
    q += qry(node->left, l, m, x);
  if(node->right != NULL)
    q += qry(node->right, m+1, r, x);

  return q;
}

void policzget(Node* node, int l, int r, Node* tolicz, ll &inv){
  if(l == r){
    inv += (ll)qry(tolicz, 1, n, l-1); // liczba elementow mniejsza od x (dlatego x-1)
    return;
  }
  int m = (l+r)/2;
  if(node->left != NULL)
    policzget(node->left, l, m, tolicz, inv);
  if(node->right != NULL)
    policzget(node->right, m+1, r, tolicz, inv);
}

void addget(Node* a, Node* b, int l, int r){ // b.size < a.size
  int m = (l+r)/2;
  if(a->left == NULL && b->left != NULL){
    a->left = new Node();
    a->left = b->left;
    b->left = NULL;

  } else if(a->left != NULL && b->left != NULL)
    addget(a->left, b->left, l, m);

  if(a->right == NULL && b->right != NULL){
    a->right = new Node();
    a->right = b->right;
    b->right = NULL;

  } else if(a->right != NULL && b->right != NULL)
    addget(a->right, b->right, m+1, r);

  a->size = 0;
  if(a->left != NULL)
    a->size += a->left->size;
  if(a->right != NULL) 
    a->size += a->right->size;

  delete b;
  b = NULL;
}

Node* foo(){
  int p; cin >> p;
  if(p){
    Node* V = new Node();
    add(V, 1, n, p);
    return V;
  }

  Node* l = foo();
  Node* r = foo();
  
  if(r->size > l->size)
    swap(l, r);
  
  ll inv1 = 0;
  policzget(r, 1, n, l, inv1);
  ll inv2 = (ll)l->size * (ll)r->size - inv1;
  
  addget(l, r, 1, n);

  ans += (ll)min(inv1, inv2);
  return l;
}

int main(){
  fastio;
  cin >> n;
  ans = 0;
  foo();
  cout << ans << "\n";
}
