#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

long long n, k;

int main(){
  fastio;
  cin >> n >> k;
  cout << k*(2*3*n - 1);
}
