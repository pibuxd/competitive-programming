#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;

int solve(){
  int height = 1;
  for(int i = 1; i <= n; i++){
    if(a[i] == 1 && a[i-1] == 1) height += 5;
    else if(a[i] == 1) height++;
    else if(a[i] == 0 && a[i-1] == 0 && i > 1) return -1;
  }

  return height;
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