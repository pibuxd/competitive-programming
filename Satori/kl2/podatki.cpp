#include <bits/stdc++.h>
using namespace std;

// Fenwick tree

typedef long long ll;

int n, q;
vector<ll> V;

void updateVal(int idx, int val){
  while(idx <= n){
    V[idx] += val;
    idx += idx & -idx;
  }
}

void update(int a, int b, int val){
  updateVal(a, val);
  updateVal(b + 1, -val);
}

void constructFenwickTree(){
  V = vector<ll>(n+1);
}

ll getElement(int x){
  ll ans = 0;

  while(x){
    ans += V[x];
    x -= x & -x;
  }

  return ans;
}

void test(){
  char operation;
  int a, b, c;
  
  while(q--){
    cin >> operation;
    
    if(operation == 'E'){
      cin >> a >> b >> c;
      update(a, b, c);
    }
    else{
      cin >> a;
      cout << getElement(a) << '\n';
    }
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;

  while(t--){
    cin >> n >> q;
    constructFenwickTree();
    test();
  }
}