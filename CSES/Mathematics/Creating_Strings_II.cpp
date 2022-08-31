#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int mxn = 1e6, M = 1e9+7;
vector<int> silnia;

void presilnia(int n){
  silnia.resize(n+1);
  silnia[1] = 1;
  for(int i = 2; i <= n; i++)
    silnia[i] = (silnia[i-1] * i) % M;
}

int quickpow(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans = (ans*a)%M;
    a = (a*a) % M;
    b /= 2;
  }
  return ans;
}

int divmod(int a, int b){
  return (a*quickpow(b, M-2)) % M;
}

signed main(){
  fastio;
  string s;
  cin >> s;
  
  presilnia(mxn);
  
  vector<int> occ(26);

  for(char i : s) occ[i-'a']++;
  
  int ans = silnia[s.size()];
  for(int i = 0; i < 26; i++)
    if(occ[i])
      ans = divmod(ans, silnia[occ[i]]);
  cout << ans << "\n";
}
