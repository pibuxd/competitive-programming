// * Trie and segment tree to find the first 1-edge and then compare depth and depth order
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Trie {
  int n;
  vector<pair<int, int>> trie, value;
  vector<int> used, first_one;

  Trie(int _n){
    n = _n;
    trie.resize(n+1);
  }

  void push(int v, int l, int r){
    trie[v] = {l, r}; 
  }

  void dfs(int v = 1, int depth = 0, int v_one = 0){
    used[depth]++;
    value[v] = {depth, used[depth]};
    first_one[v] = v_one;

    if(trie[v].first){
      dfs(trie[v].first, depth+1, v_one);
    }
    if(trie[v].second){
      if(!v_one) v_one = v;
      dfs(trie[v].second, depth+1, v_one);
    }
  }

  void build(){
    value.resize(n+1);
    used.resize(n+1);
    first_one.resize(n+1);
    dfs();
  }

  bool compare(int a, int b){
    if(first_one[b] == 0){
      //cout << "0 ";
      return true;
    }
    if(value[a].first-value[first_one[a]].first > value[b].first-value[first_one[b]].first){
      //cout<<"1 ";
      return true;
    }
    else if(value[a].first-value[first_one[a]].first == value[b].first-value[first_one[b]].first){
      if(value[a].second >= value[b].second){
        //cout<<"2 ";
        return true;
      }
      //cout<<"3 ";
      return false;
    }
    //cout<<"4 ";
    return false;
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

  trie.build();

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
  /*
  cout << "\nDEPTH,USED:\n";
  for(auto x : trie.value){
    cout << x.first << ',' << x.second << '\n';
  }
  cout << "\nFIRST_ONE:\n";
  for(auto x : trie.first_one){
    cout << x << '\n';
  }
  */
}