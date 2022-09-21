#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int unsigned int
#define ll unsigned long long

const int nmax = 20;
int n, szuk, mid;
vector<int> a;
unordered_map<int, bitset<nmax>> M;

void foo(int st, int sum, int it, bitset<nmax> b, int kon){
  if(sum > szuk) return;
  if(it > kon){
    M.insert({sum, b});
    return;
  }
  foo(st, sum, it+1, b, kon);
  foo(st, sum+a[it], it+1, bitset<nmax>(b.to_ullong()+((ll)1<<it-st)), kon);
}

ll FOO(int st, int sum, int it, bitset<nmax> b, int kon){
  if(sum > szuk) return 0;
  if(it > kon){
    if(M.count(szuk-sum)) 
      return ((b.to_ullong()<<st-1) + M[szuk-sum].to_ullong());
    return 0;
  }
  ll f1 = FOO(st, sum, it+1, b, kon);
  if(f1) return f1;
  ll f2 = FOO(st, sum+a[it], it+1, bitset<nmax>(b.to_ullong()+((ll)1<<it-st)), kon);
  if(f2) return f2;
  return 0;
}

string szyfr(ll b){
  string res = "";
  for(int i = 1; i <= n; i++){
    if(b & ((ll)1<<i-1))
      res += '1';
    else
      res += '0';
  }
  return res;
}

signed main(){
  fastio;
  cin >> n;
  mid = n/2;
  a.assign(n+1, 0);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  cin >> szuk;
  
  foo(1, 0, 1, {}, mid);
  for(auto &i : M){
    if(i.first == szuk){
      cout << szyfr(i.second.to_ullong()) << "\n";
      return 0;
    }
  }

  ll P = FOO(mid+1, 0, mid+1, {}, n);
  if(P){
    cout << szyfr(P) << "\n";
    return 0;
  }

  M.clear();
  foo(mid+1, 0, mid+1, {}, n);
  for(auto &i : M){
    if(i.first == szuk){
      cout << szyfr((i.second.to_ullong() << mid)) << "\n";
      return 0;
    }
  }
}
