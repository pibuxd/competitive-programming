#include<bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;
  long long sum = 0, t = (n*(n+1))/2;

  while(n > 1){
    int p; cin >> p;
    sum += p;
    n--;
  }
  cout << t- sum;
}
