// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int N, L;
vector<string> v;

bool check(int l, int r){
  int len = r-l+1;

  vector<string> sub(N+1);
  for(int i = 1; i <= N; i++)
    sub[i] = v[i].substr(l-1, len);

  for(int i = 2; i <= N; i++){
    if(sub[i-1] >= sub[i])
      return false;
  }

  return true;
}

int main(){
  fastio;
  cin >> N >> L;

  v.resize(N+1);

  for(int i = 1; i <= N; i++)
    cin >> v[i];

  int mn = L, l = 1, r = L;

  for(int i = 1; i <= L; i++){
    for(int j = i; j <= L; j++){
      int len = j-i+1;
      bool ok = check(i, j);

      if(ok){
        if(mn > len){
          mn = len;
          l = i, r = j;
        }
      }
    }
  }

  cout << l << " " << r;
}