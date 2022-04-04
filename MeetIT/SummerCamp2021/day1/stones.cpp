// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;

int main(){
  fastio;
  ll x, y;
  cin >> x >> y;
  cout << (abs(x-y) <= 1 ? "Kacper" : "Marta");
}