#include <bits/stdc++.h>
using namespace std;

void sieve(int n){
  vector<bool> isprime(n+1, true);
  isprime[0] = isprime[1] = false;
  
  for(int i = 2; i <= n; i++)
    if(isprime[i])
      for(int j = i*i; j <= n; j++)
        isprime[j] = false;
}
