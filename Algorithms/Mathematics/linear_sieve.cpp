#include <bits/stdc++.h>
using namespace std;

void sieve(int n){
  vector<bool> vis(n+1, false);
  vector<int> primes;

  for(int i = 2; i <= n; i++){
    if(!vis[i]){
      primes.push_back(i);
      vis[i] = true;
    }
    for(int p : primes){
      if(i * p <= n)
        vis[i * p] = true;
      else
        break;
      if(i % p == 0) 
        break;
    }
  }
}
