#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int n, p, mx, medit;
vector<int> a, b;

int podz1(){ // O(n * n)
  vector<int> tab;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int val = (a[i] * b[j]) % p;
      tab.push_back(val);
      cout << val << "\t";
    }
    cout << "\n";
  }
  sort(all(tab));
  //for(int i = 0; i < n*n; i++) cout << i+1 << ": " << tab[i] << "\n";
  return tab[medit - 1];
}

// ile w tab jest mniejszych rownych od m
int check(int m){
  int res = 0;
  for(int i = 1; i <= n; i++){
    int x = m / a[i];
    auto it = upper_bound(all(b), x);
    it--;
    res += (it - b.begin());
  }
  return res;
}

int podz2(){ // O(n * logn * logn)
  //cout << "\n";
  mx = a[n]*b[n];
  //cout << check(3) << "\n";
  //return 0;
  int l = 0, r = mx;
  while(l < r){
    int m = (l+r)/2;
    
    // ilosc liczb mniejszych od m
    int ch = check(m);
    if(ch == medit) return m;
    if(ch > medit && check(m-1) <= medit) return m;
    if(ch < medit && check(m+1) >= medit) return m;
    // jesli m jest na prawo od mediany (0 ... med ... m ... n*n)
    if(ch >= medit)
      r = m-1;
    else // jesli m jest na lewo od mediany (0 ... m ... med ... n*n)
      l = m+1;
  }
  return l;
}

int solve(){
  medit = (n*n)/2 + (n*n)%2;
  sort(all(a)); sort(all(b));
  return podz1();
  if(p > a[n]*b[n]) return podz2();
  else return podz1();
}

signed main(){
  fastio;
  cin >> n >> p;
  a.resize(n+1, 0);
  b.resize(n+1, 0);
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> b[i];
  cout << solve() << "\n";
}
