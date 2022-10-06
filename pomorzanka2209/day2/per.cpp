#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<int> p, pit, par, nxt, up, nxtit;

struct node {
  int val;
  node* l;
  node* r;
};

node* newnode(int val, node* l, node* r){
  node* nd = new node;
  nd->val = 0, nd->l = l, nd->r = r;
  return nd;
}

void build(int l, int r, node* v, vector<int> &tab){
  if(l == r){
    v->val = tab[l];
    v->l = v->r = NULL;
    return;
  }
  int m = (l+r)/2;
  node* ln = newnode(0, NULL, NULL);
  node* rn = newnode(0, NULL, NULL);
  v->l = ln, v->r = rn;
  build(l, m, v->l, tab);
  build(m+1, r, v->r, tab);
  v->val = max(ln->val, rn->val);
}

int qry(node* v){
  return v->val;
}

int main(){
  fastio;
  cin >> n >> k;
  p.assign(n+2, 0);
  pit.assign(n+2, 0);
  par.assign(n+2, 0);
  nxt.assign(n+2, 0);
  nxtit.assign(n+2, 0);
  up.assign(n+2, 0);
  
  for(int i = 1; i <= n; i++){
    cin >> p[i];
    par[p[i]-1] = i;
    pit[p[i]] = i;
  }
  par[n] = n+1;

  //for(int i = 1; i <= n; i++) cout << par[p[i]] << " "; cout << "\n";
  
  int v = 0;
  while(v <= n){
    nxt[pit[v]] = par[v];
    up[par[v]] = pit[v];
    //cout << nxt[pit[v]] << " ";
    nxtit[v] = nxt[pit[v]];
    v++;
  }
  for(int i = 0; i <= n; i++) cout << nxtit[i] << " "; cout << "\n";

  node* rot = newnode(0, NULL, NULL);
  build(0, n+1, rot, nxtit);

  for(int i = n; i >= 0; i--){
    
  }
}
