#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n;

int nearestpow(int v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++; // next power of 2
    return v;
}

vector<int> ans(){
  if(n == 3) return {0, 2, 1, 3};
  if(n == 4) return {0, 2, 1, 3, 0};
  if(n == 5) return {0, 2, 0, 4, 5, 3};
  if(n == 6) return {0, 4, 1, 2, 12, 3, 8};
  if(n == 7) return {0, 1, 2, 3, 4, 5, 6, 7};
  if(n == 8) return {0, 4, 2, 1, 5, 0, 6, 7, 3};
  if(n == 9) return {0, 8, 2, 3, 7, 4, 0, 5, 6, 9};

  vector<int> A(n+1);
  int X = 0, Y = 0;
  int eX = n-(n%2==0), eY = n-(n%2==1);

  for(int i = 1; i < eX-4; i += 2){
    A[i] = i;
    X ^= i;
  }
  for(int i = 2; i < eY-4; i += 2){
    A[i] = i;
    Y ^= i;
  }

  int n2 = nearestpow(eX+1);
  A[eX-4] = n2;
  X ^= n2;
  A[eX-2] = n2*2;
  X ^= n2*2;
  A[eX] = X;

  int N2 = nearestpow(8*eY);
  A[eY-4] = N2;
  Y ^= N2;
  A[eY-2] = N2*2;
  Y ^= N2*2;
  A[eY] = Y;

  return A;
}

signed main(){
  fastio;
  int t; cin >> t;

  while(t--){
    cin >> n;
    vector<int> _ANS = ans();
    for(int i = 1; i <= n; i++)
      cout << _ANS[i] << " ";
    cout << "\n";
  }
}
