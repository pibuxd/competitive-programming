// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int n;
  cin >> n;

  string ans = "";
  vector<char> a(n+1);
  int op = 0;

  for(int i = 1; i <= n-1; i++){
    cin >> a[i];

    if(i == 1)
      ans += "-";
    else if(a[i-1] == '-' && a[i] == '+')
      ans += "(-", op++;
    else if(a[i-1] == '+' && a[i] == '-')
      ans += ")-", op--;
    else
      ans += "-";
  }

  while(op--)
    ans += ")";

  cout << ans << '\n';
}