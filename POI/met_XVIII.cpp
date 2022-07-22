#include "bits/stdc++.h"
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, m, k, addedto;
vector<int> required, tree, lazy;
vector<vector<int>> sectorsof;
vector<array<int, 3>> rains;

void push_down(int v){
  if(lazy[v] == 0)
    return;
  lazy[2*v] += lazy[v];
  lazy[2*v+1] += lazy[v];
  tree[2*v] += lazy[v];
  tree[2*v+1] += lazy[v];
  lazy[v] = 0;
}

void add(int v, int l, int r, int a, int b, int val){
  if(l > b || r < a)
    return;
  if(a <= l && r <= b){
    tree[v] += val;
    lazy[v] += val;
    return;
  }
  push_down(v);
  int mid = (l+r)/2;
  add(2*v, l, mid, a, b, val);
  add(2*v+1, mid+1, r, a, b, val);
  tree[v] = tree[2*v] + tree[2*v+1];
}

void add(int l, int r, int val){
  //cout << "ADD: " << l << ", " << r << ", " << val << "\n";
  if(l <= r)
    add(1, 1, m, l, r, val);
  else 
    add(1, 1, m, l, m, val), add(1, 1, m, 1, r, val);
}

int get(int v, int l, int r, int idx){
  if(l == r)
    return tree[v];

  push_down(v);
  int mid = (l+r)/2;
  if(mid >= idx)
    return get(2*v, l, mid, idx);
  else
    return get(2*v+1, mid+1, r, idx);
}

void addallupto(int to){
  while(addedto < to)
    addedto++, add(rains[addedto][0], rains[addedto][1], rains[addedto][2]);
  while(addedto > to)
    add(rains[addedto][0], rains[addedto][1], -rains[addedto][2]), addedto--;
}

bool check(int station){
  int sum = 0;
  for(int nr : sectorsof[station])
    sum += get(1, 1, m, nr);
  
  return sum >= required[station];
}

signed main(){
  fastio;
  cin >> n >> m;

  sectorsof.assign(m+1, vector<int>());
  required.assign(n+1, 0);
  for(int i = 1; i <= m; i++){ int ow; cin >> ow; sectorsof[ow].push_back(i); }
  for(int i = 1; i <= n; i++) cin >> required[i];

  cin >> k;
  rains.assign(k+1, array<int, 3>());
  for(int i = 1; i <= k; i++) cin >> rains[i][0] >> rains[i][1] >> rains[i][2];
  
  priority_queue<array<int, 4>> PQ;
  for(int i = 1; i <= n; i++) PQ.push({(1+k)/2, 1, k, i});
  
  addedto = 0;
  vector<int> ans(n+1);
  tree.assign(4*m+1, 0);
  lazy.assign(4*m+1, 0);
  while(!PQ.empty()){
    vector<array<int, 4>> tocheck{};
    tocheck.push_back(PQ.top());
    PQ.pop();

    while(!PQ.empty() && PQ.top()[0] == tocheck[0][0]){
      tocheck.push_back(PQ.top());
      PQ.pop();
    }
    
    int mid = tocheck[0][0];
    addallupto(mid);
    for(auto c : tocheck){
      int l = c[1], r = c[2], idx = c[3];
      //cout << mid << ", " << l << ", " << r << ", " << idx << "\n"; 
      bool ch = check(idx);
      if(l == r){
        if(l == k){
          if(ch)
            ans[idx] = k;
          else
            ans[idx] = -1;
        }
        else
          ans[idx] = l;
      } else{
        if(ch)
          PQ.push({(l+mid)/2, l, mid, idx});
        else
          PQ.push({(mid+1+r)/2, mid+1, r, idx});
      } 
    }
    //cout << "-------------------------------\n";
  }

  for(int i = 1; i <= n; i++) cout << (ans[i] == -1 ? "NIE" : to_string(ans[i])) << "\n";
}   
