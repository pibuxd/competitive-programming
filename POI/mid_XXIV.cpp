// tree on pointers in order to count preorder equally
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Node {
  vector<int> V;
  Node *l = NULL;
  Node *r = NULL;

  Node(vector<int> _V = {}, Node *_l = NULL, Node *_r = NULL){
    V = _V, l = _l, r = _r;
  }
};

int n, nr;
vector<pair<int, int>> G;
vector<int> pre, d;
Node* t;

void dfscr(int v, Node* c){
  if(v == 0) return;
  auto [l, r] = G[v];
  c->V.push_back(v);
  if(c->l == NULL)
    c->l = new Node();
  if(c->r == NULL)
    c->r = new Node();
  dfscr(l, c->l);
  dfscr(r, c->r);
}

void newdfs(int v){
  auto [l, r] = G[v];
  if(r) dfscr(r, t);
  if(l) newdfs(l);
}

void predfs(Node* c, int h){
  nr++;
  for(auto x : c->V)
    pre[x] = nr, d[x] = h;
  if(c->l != NULL)
    predfs(c->l, h+1);
  if(c->r != NULL)
    predfs(c->r, h+1);
}

signed main(){
  fastio;
  cin >> n;
  G.resize(n+1);
  pre.resize(n+1, 0);
  d.resize(n+1, 0);

  for(int i = 1; i <= n; i++){
    int l, r; cin >> l >> r;
    G[i] = {l, r};
  }
  t = new Node();
  newdfs(1);
  nr = 0;
  predfs(t, 1);

  int z; cin >> z;
  while(z--){
    int a, b; cin >> a >> b;
    if(d[a] > d[b] || (d[a] == d[b] && pre[a] >= pre[b]))
      cout << "TAK\n";
    else
      cout << "NIE\n";
  }
}
