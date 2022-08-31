#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int lan, k, mxn = 2e6, M = 1e9+7, lozd;
vector<int> a, silnia;

int quickpow(int a, int b){
  int sum = 1;
  while(b >= 1){
    if(b % 2 == 1){
      sum = (sum * a) % M, b--;
      continue;
    }
    b /= 2;
    a = (a * a) % M;
  }
  return sum;
}

void presilnia(int n){
  silnia.resize(n+1);
  silnia[1] = 1;
  for(int i = 2; i <= n; i++)
    silnia[i] = (silnia[i-1] * i) % M;
}

int divmod(int a, int b){
  return (a * quickpow(b, M-2)) % M;
}

int lperm(){
  int licznik, mian = 1;
  for(int i = 1; i <= k; i++)
    mian = (mian * silnia[a[i]]) % M;

  licznik = silnia[lozd];
  int res = divmod(licznik, mian);
  return res;
}

int spospodz(){
  int licznik = silnia[lozd+lan-1];
  int mianownik = (silnia[lan-1] * silnia[lozd]) % M;
  int res = divmod(licznik, mianownik);
  return res;
}

signed main(){
  fastio;
  cin >> lan >> k;
  
  a.resize(k+1);
  lozd = 0;
  for(int i = 1; i <= k; i++){
    cin >> a[i];
    lozd += a[i];
  }

  presilnia(mxn);
  cout << (lperm() * spospodz()) % M << "\n";
  
}
