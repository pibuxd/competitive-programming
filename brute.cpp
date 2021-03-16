#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, q;
vector<int> T;

void update(int a, int b, int val){
  for(;a <= b; a++){
    T[a] = val;
  }
}

int query(int a, int b){
  int maximum = -1;

  for(;a <= b; a++){
    if(T[a] > maximum){
      maximum = T[a];
    }
  }

  return maximum;
}

int main(){
  fastio;

  cin >> n >> q;
  T = vector<int>(n+1);

  while(q--){
    int a, b;
    cin >> b >> a;
    b--;

    int maximum = query(a, a+b);
    cout << maximum << endl;
    update(a, a+b, maximum+1);
  }

  cout << query(1, n);
}