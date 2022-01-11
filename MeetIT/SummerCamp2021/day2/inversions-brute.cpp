
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ans;
vector<int> a;

int main(){
  fastio;
  a.resize(n+1);
  ans = 0;

  cin >> n >> k;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }

  for(int i = 1; i <= n; i++){
    for(int j = i; j <= n; j++){
      int temp = 0;
      for(int l = i; l <= j; l++){
        for(int r = l; r <= j; r++){
          if(a[l] > a[r])
            temp++;
        }
      }
      if(temp <= k)
        ans++;
    }
  }

  cout << ans;
}