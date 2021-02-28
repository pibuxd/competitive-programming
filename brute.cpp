/**
 * * brute
 * lazy propagation segment tree
 * * range subtract, range minimum
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m, q;
vector<int> T;

void update(int a, int b, int val){
  for(;a <= b; a++){
    T[a] -= val;
  }
}

int query(int a, int b){
  int minimum = INT_MAX;

  for(;a <= b; a++){
    if(T[a] < minimum){
      minimum = T[a];
    }
  }

  return minimum;
}

int main(){
  fastio;
  int t;
  cin >> t;
 
  while(t--){
    cin >> n >> m >> q;
    T = vector<int>(n+1, m);

    while(q--){
      int tempa, tempb, val;
      cin >> tempa >> tempb >> val;

      tempb--; // ?
      int a = min(tempa, tempb);
      int b = max(tempa, tempb);
      int minimum = query(a, b);
 
      if(val <= minimum){
        cout << "T\n";
        update(a, b, val);
      } else{
        cout << "N\n";
      }
    }
  }
}