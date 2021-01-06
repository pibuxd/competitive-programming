#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  long long n, p, sum = 0, A = 0; cin >> n; set<long long> S;
  for(long long i = 0; i < n; i++){
    cin >> p; S.insert(p);
  }
  for(long long i = 0; i < S.size(); i++){
    A += S.upper_bound(1000); S.erase(n-i);
    i++;
    A -= S.upper_bound(100); S.erase(n-i);
  }
  cout << A;
}
