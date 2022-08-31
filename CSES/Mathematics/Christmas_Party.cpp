#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, m, M = 1e9+7, mxn = 2e6;
vector<int> silnia;

int quickpow(int a, int b){
  int ans = 1;
  while(b > 0){
    if(b % 2 == 1)
      ans = (ans * a)%M;
    a = (a*a)%M;
    b /= 2;
  }
  return ans;
}

int divmod(int a, int b){
  return (a * quickpow(b, M-2))%M;
}

int newton(int a, int b){
  int res = silnia[a];
  res = divmod(res, silnia[b]);
  res = divmod(res, silnia[a-b]);
  return res;
}

void presilnia(){
  silnia.assign(mxn+1, 0);
  silnia[0] = 1;
  for(int i = 1; i <= mxn; i++)
    silnia[i] = (silnia[i-1] * i)%M;
}

signed main(){
  fastio;
  cin >> n;
  mxn = n;
  presilnia();

  int ans = 0;
  for(int i = 0; i <= n; i++){
    if(i % 2 == 1){
      ans = (ans - divmod(silnia[n], silnia[i])%M)%M;
    } else{
      ans = (ans + divmod(silnia[n], silnia[i])%M)%M;
    }
  }

  cout << (ans+M)%M << "\n";
}
