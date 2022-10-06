#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int unsigned long long

int n, p, mxa, medit;
vector<int> a, b;

int podz1(){ // O(n * n)
  vector<int> tab;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      int val = (a[i] * b[j]) % p;
      tab.push_back(val);
    }
  }
  sort(all(tab));
  return tab[medit - 1];
}

int trimto(int m){
  int cand = 0;

  for(int i = 1; i <= n; i++){
    int x = m / a[i];
    auto it = lower_bound(all(b), x);
    if(*it == x && m % a[i] == 0)
      return m;
    int newcand = (*it) * a[i];
    if(newcand > 0 && newcand < m)
      cand = max(cand, newcand);
  }
  return cand;
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
  if(n == 1) return a[1]*b[1];
  mxa = a[n]*b[n];
  int l = 1, r = mxa, med = 0;
  while(l < r){
    int m = (l+r)/2;
    
    // ilosc liczb mniejszych od m
    int ch = check(m);
    if(ch == medit){ 
      med = m;
      break;
    }
    if(ch > medit && check(m-1) < medit){
      med = m;
      break;
    }
    
    if(ch >= medit) // jesli m jest na prawo od mediany (0 ... med ... m ... n*n)
      r = m-1;
    else // jesli m jest na lewo od mediany (0 ... m ... med ... n*n)
      l = m+1;
  }
  med = trimto(med);
  return med;
}

int solve(){
  medit = (n*n)/2 + (n*n)%2;
  sort(all(a)); sort(all(b));
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
