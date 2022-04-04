// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<iostream>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int F[1000001];
  F[0] = 1; F[1] = 1; F[2] = 2;

  for(int n = 3; n <= 1000001; n++)
    F[n] = (F[n - 1] + F[n - 2]) % 1073741824;

  int z; cin >> z;
  int s, p;
  for(int i = 0; i < z; i++){
    cin >> s >> p;
    int po = 1 << p;
    cout << F[s] % po << '\n';
  }
}
