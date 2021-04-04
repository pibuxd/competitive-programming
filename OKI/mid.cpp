#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Trie {
  vector<pair<int, int>> tree;
  vector<pair<int, int>> value;
  vector<int> used;
  int n;

  Trie(int _n){
    n = _n;
    tree.resize(n+1);
  }

  void push(int v, int l, int r){
    tree[v] = {l, r}; 
  }

  void dfs(int v, int depth){
    value[v] = {depth, used[v]};
    used[v]++;

    if(tree[v].first){
      dfs(tree[v].first, depth+1);
    }
    if(tree[v].second){
      dfs(tree[v].second, depth+1);
    }
  }

  void build(int start){
    value.resize(n+1);
    used.resize(n+1, 1);

    dfs(start, 0);
  }

  bool compare(int a, int b){
    if(value)
  }
};

int main(){
  fastio;

  int n;
  cin >> n;

  Trie trie(n);

  for(int i = 1, l, r; i <= n; i++){
    cin >> l >> r;
    trie.push(i, l, r);
  }

  trie.build(1);

  int q;
  cin >> q;

  for(int a, b; q--;){
    cin >> a >> b;

    if(trie.compare(a, b)){
      cout << "TAK\n";
    } else{
      cout << "NIE\n";
    }
  }
}