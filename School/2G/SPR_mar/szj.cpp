// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h> 
using namespace std;  
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int custom_modulo(int i, int mod){
  if(i%mod == 0) return mod;
  else return i%mod;
}

int main(){
  fastio;
  int n;  
  cin >> n;

  vector<int> klucz(n+1);

  for(int i = 1; i <= n; i++){
    cin >> klucz[i];
  }

  string m;
  cin >> m;

  for(int i = 0; i < m.size(); i++){
    m[i] += klucz[custom_modulo(i+1, n)];
  }

  cout << m;
} 