#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n, LOGN = 19, sum;
vector<int> a, ai;
vector<vector<int>> sparse;

void build(){
  for(int j = 1; j <= LOGN-1; j++)
    for(int i = 1; i + (1 << (j-1)) <= n; i++)
      sparse[i][j] = max(sparse[i][j-1], sparse[i+(1<<(j-1))][j-1]);
}

int query(int a, int b){
  if(a > b)
    swap(a, b);
  int len = b - a + 1;
  int j = floor(log2(len));
  return max(sparse[a][j], sparse[b-(1<<j)+1][j]);
}

void foo(int L, int R){
  if(R-L+1 <= 2) return;

  int mx = query(L, R);
  int mxi = ai[mx];

  if(mxi-L <= R-mxi){
    for(int i = L; i <= mxi-1; i++){
      if(mxi+1 <= ai[mx-a[i]] && ai[mx-a[i]] <= R)
        sum++;
    }
  } else{
    for(int i = R; i >= mxi+1; i--){
      if(L <= ai[mx-a[i]] && ai[mx-a[i]] <= mxi-1)
        sum++;
    }
  }

  foo(L, mxi-1);
  foo(mxi+1, R);
}

signed main(){
  fastio;
  cin >> n;

  a.resize(n+1);
  ai.resize(n+1);
  sparse.resize(n+1, vector<int>(LOGN+1));

  for(int i = 1; i <= n; i++){
    cin >> a[i];
    ai[a[i]] = i;
    sparse[i][0] = a[i];
  }

  build();
  sum = 0;

  foo(1, n); 

  cout << sum << "\n";
}