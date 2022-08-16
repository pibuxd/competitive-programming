// number theory
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()

// in this problem I assume that 2 is not a prime number
vector<int> primes;
vector<vector<int>> pre;

void sieve(int n){
  vector<bool> isprime(n+1, true);
  isprime[0] = isprime[1] = isprime[2] = false;

  for(int i = 2; i <= n; i++){
    if(!isprime[i] && i != 2)
      continue;
    if(isprime[i])
      primes.push_back(i);
    if(i*i > n)
      continue;
    for(int j = i*i; j <= n; j += i){
      isprime[j] = false;
    }
  }
}

void foo(int k, int sum, int pi, vector<int> currprimes){
  if(primes[pi] > k)
    return;

  foo(k, sum, pi+1, currprimes);

  int sumnew = sum + primes[pi];
  currprimes.push_back(primes[pi]);
  pre[sumnew] = currprimes;
  
  foo(k, sumnew, pi+1, currprimes);
}

void genex(int k){
  pre.assign(76, vector<int>());
  foo(k, 0, 0, {});
}

int calc(int n, vector<int> &v, int plast){
  if(n <= 65) // koniec rekursji
    return n;
  
  int d = n-20;
  auto plastit = lower_bound(all(primes), plast);
  if(plast <= primes.back())
    plastit--;
  auto it = upper_bound(primes.begin(), plastit, d);
  it--;
  v.push_back(*it);
  return calc(n-(*it), v, *it);
}

signed main(){
  fastio;
  sieve(1000000);
  // for(int p : primes) cout << p << " "; cout << "\n";
  int k = 19; // pierwszy (najwiekszy) prime number jakiego nie moge uzyc w calc()
  genex(k);

  // for(int i = 1; i <= 75; i++){
  //   cout << i << ": ";
  //   for(int p : pre[i]) cout << p << " ";
  //   cout << "\n";
  // }

  int t;
  cin >> t;
  while(t--){
    int x;
    cin >> x;
    vector<int> ans;
    int zostalo = calc(x, ans, 1e9);
    if(zostalo)
      for(int i = pre[zostalo].size()-1; i >= 0; i--)
        ans.push_back(pre[zostalo][i]);

    cout << ans.size() << "\n";
    for(int i = ans.size()-1; i >= 0; i--) 
      cout << ans[i] << " ";
    cout << "\n";
  }
}