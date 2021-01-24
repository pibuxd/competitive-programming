#include <bits/stdc++.h>
using namespace std;
 
// Fenwick tree

int n, q;
vector<int> V;

void updateVal(int l, int r, int val){
  V[l] += val;
  if(r < n)
    V[r+1] -= val;
}

void initData(){
  cin >> n >> q;
  V = vector<int>(n+1);

  for(int i = 1, x; i <= n; i++){
    cin >> x;
    updateVal(i, i, x);
  }
}

int getElement(int x){
  int ans = 0;

  for(int i = 1; i <= x; i++){
    ans += V[i];
  }

  return ans;
}

void test(){
  int a, b, c, operation;
  
  while(q--){
    cin >> operation >> a;
    
    if(operation == 1){
      cin >> b >> c;
      updateVal(a, b, c);
    }
    else{
      cout << getElement(a) << '\n';
    }
  }
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  initData();
  test();
}