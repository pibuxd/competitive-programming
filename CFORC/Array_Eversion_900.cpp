#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;

int solve(){
  int k = 0;

  int big = a[n];
  for(int i = n; i >= 1; i--){
    if(a[i] > big){
      big = a[i];
      k++;
    }
  }

  return k;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    a.resize(n+1);
    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }

    cout << solve() << "\n";
  }
}