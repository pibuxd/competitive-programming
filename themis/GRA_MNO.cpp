#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int N;

int c(int a, int b){
  return (a/b + (a%b > 0));
}

int f(int a, int b){
  return a/b;
}

string solve(){
  cin >> N;
  if(N <= 9) return "TAK";

  bool ruch = 1; // 1-Alicja, 0-Bob
  int x = N-1, y = c(N, 9);

  while(y > 1){
    ruch = (ruch == 1 ? 0 : 1);

    if(ruch == 0){ // P
      x = f(x, 9), y = c(y, 2);
    } else{ // M
      x = f(x, 2), y = c(y, 9);
    }
  }

  return (ruch == 1 ? "TAK" : "NIE");
}

signed main(){
  fastio;
  int q; cin >> q;
  while(q--) cout << solve() << "\n";
}
