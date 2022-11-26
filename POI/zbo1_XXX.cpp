// autor - Piotr Bublik
// implementacja rozbicia przez centroid https://usaco.guide/plat/centroid?lang=cpp#implementation-1
// pomysl inspirowany tym artykulem https://medium.com/carpanese/an-illustrated-introduction-to-centroid-decomposition-8c1989d53308
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

int n, k;
vector<vector<pair<int, int>>> G;
vector<int> sub;
vector<ll> distsub, sub_num, distsub_fromtree;
vector<bool> wyrzucony;
vector<vector<array<ll, 2>>> down;

void dfssub(int v, int p){
  sub[v] = 1;
  for(auto [x, w] : G[v]) if(x != p && !wyrzucony[x]){
    dfssub(x, v);
    sub[v] += sub[x];
  }
}

int find_centroid(int v, int treesize, int p){
  for(auto [x, w] : G[v]) if(x != p && !wyrzucony[x] && sub[x]*2 > treesize) return find_centroid(x, treesize, v);
  return v;
}

void dfsdist(int v, int p, ll d, int root){
  down[v].push_back({root, d});
  for(auto [x, w] : G[v]) if(x != p && !wyrzucony[x]) dfsdist(x, v, d+(ll)w, root);
}

void centroid_dec(int v){
  dfssub(v, 0);
  int C = find_centroid(v, sub[v], 0);
  dfsdist(C, 0, 0, C);

  wyrzucony[C] = true;
  for(auto [x, w] : G[C]) if(!wyrzucony[x]) centroid_dec(x);
}

ll build_castle(int d){
  ll sum = 0;
  for(int dit = 0; dit < down[d].size()-1; dit++){
    array<ll, 2> &a = down[d][dit]; // kolejny wierzcholek na sciezce drzewa centroidow
    array<ll, 2> &b = down[d][dit+1]; // dziecko a z poddrzewa ktore idzie do d

    sum += distsub[a[0]] - distsub_fromtree[b[0]] + (sub_num[a[0]] - sub_num[b[0]]) * a[1];
    distsub[a[0]] += a[1];
    distsub_fromtree[b[0]] += a[1];
    sub_num[a[0]]++;
  }
  sum += distsub[d];
  sub_num[d]++;

  return sum;
}

signed main(){
  fastio;
  cin >> n >> k;

  G.resize(n+1);
  down.resize(n+1);
  distsub.resize(n+1, 0);
  distsub_fromtree.resize(n+1, 0);
  sub_num.resize(n+1, 0);
  sub.resize(n+1, 0);
  wyrzucony.resize(n+1, false);

  for(int i = 1; i <= n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }

  centroid_dec(1);
  ll answer = 0;
  build_castle(1);
  
  while(k--){
    int d; cin >> d;
    answer += build_castle(d);
    cout << (answer << 1) << "\n"; // bo liczymy z A do B oraz z B do A, wiec mnozymy x2
  }
}
