#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, H;

int main(){
  fastio;
  cin >> n >> H;

  int ans = 0, cnt = 0;
  for(int i = 1; i <= n; i++){
    char c; cin >> c;
    if(c == '(') cnt++;
    else cnt--;

    if(cnt > H) cnt -= 2, ans++;
    if(cnt < 0) cnt += 2, ans++;
  }

  cout << ans << "\n";
}
