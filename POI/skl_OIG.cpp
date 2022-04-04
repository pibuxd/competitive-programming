// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  long long n, P, V[1000000], J[1000000], S[1000000], g = 0; cin >> n; P = n;
  for(long long i = 0, a, b; i < n; i++){
    cin >> a >> b;
    if(V[a] > 0) {P--;}
    else {S[g] = a; g++;}
    V[a] += b;
  }
  cout << P << '\n';
  for(long long i = 0; i < P; i++){
    cout << S[i] << " " << V[S[i]] << '\n';
  }
}
