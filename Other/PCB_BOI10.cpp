#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, mxv = 1e6+1;
vector<array<int, 2>> v;

bool comp(const array<int, 2> &a, const array<int, 2> &b){
  return a[1] < b[1];
}

// longest increasing sequence
int lis(vector<int> &A){
  vector<int> lenv(n, 0);
  lenv[0] = A[1];
  int len = 1;

  for(int i = 2; i <= n; i++){
    auto b = lenv.begin(), e = lenv.begin() + len;
    auto it = lower_bound(b, e, A[i]);

    if(it == e)
      lenv[len++] = A[i];
    else
      *it = A[i];
  }

  return len;
}

int main(){
  fastio;
  cin >> n;
  v.resize(n+1);

  for(int i = 1; i <= n; i++){
    int a, b; cin >> a >> b;
    a++, b++;
    v[i] = {a, b};
  }

  sort(all(v), comp);
  vector<int> A(n+2);

  for(int i = 1; i <= n; i++)
    A[i] = v[i][0];
  reverse(all(A)); // gdybym nie zrobil reverse musialbym liczyc longest decreasing sequence
                   
  //for(int i = 1; i <= n; i++) cout << i << ": " << A[i] << "\n";
  cout << lis(A) << "\n";
}
