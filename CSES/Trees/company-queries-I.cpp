#include <bits/stdc++.h>
using namespace std;

// binary lifting

const int MXN = 2e5, LOG2N = 18;
int n, q;
int up[LOG2N][MXN+1];

int jump(int a, int d){
  for(int i = 0; i < LOG2N; i++){
    if((d >> i) & 1){
      a = up[i][a];
    }
  }

  if(!a){
    return -1; 
  }

  return a;
}

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> q;

  for(int i = 2, a; i <= n; i++){
    cin >> a;
    up[0][i] = a;
  }

  for(int i = 1; i < LOG2N; i++){
    for(int j = 1; j <= n; j++){
      up[i][j] = up[i-1][up[i-1][j]];
    }
  }

  for(int a, b; q--;){
    cin >> a >> b;
    cout << jump(a, b) << '\n';
  }
}