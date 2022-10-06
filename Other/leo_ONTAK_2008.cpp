// modulo cycles
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int M = 1e9;
const int M2 = 512;
const int M5 = 1953125;
const int cycle2len = 384;
const int cycle5len = 7812500;
int n, k;

int quickpow(int a, int b, int mod){
  int res = 1 % mod;
  while(b > 0){
    if(b % 2 == 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}

signed main(){
  cin >> n >> k;
  n++;

  int f0 = 1, f1 = 3;
  
  int cycle2sum = 1;
  int sum2 = 0;
  if(n % cycle2len == 1) sum2 += 1;

  int licz = 2;
  while(!(f0 == 1 && f1 == 1)){
    cycle2sum = (cycle2sum + quickpow(f0, k, M2)) % M2;

    if(n % cycle2len == licz)
      sum2 += cycle2sum;

    int f2 = (f0+f1+1) % M2;
    f0 = f1, f1 = f2;
    licz++;
  }
  sum2 += ((n / cycle2len) * cycle2sum) % M2;

  f0 = 1, f1 = 3;
  
  int cycle5sum = 1;
  int sum5 = 0;
  if(n % cycle5len == 1) sum5 += 1;

  licz = 2;
  while(!(f0 == 1 && f1 == 1)){
    cycle5sum = (cycle5sum + quickpow(f0, k, M5)) % M5;

    if(n % cycle5len == licz)
      sum5 += cycle5sum;

    int f2 = (f0+f1+1) % M5;
    f0 = f1, f1 = f2;
    licz++;
  }
  sum5 += ((n / cycle5len) * cycle5sum) % M5;
  int t = 0;
  while((sum2 + (t * M2)%M) % M5 != sum5)
    t++;

  int res = (sum2 + (t * M2)%M) % M;

  int dz = 1e8;
  while(dz >= 1 && res < dz){
    cout << '0';
    dz /= 10;
  }

  cout << res << "\n";
}
