#include <bits/stdc++.h>
using namespace std;

int main(){
  int t; cin >> t;

  while(t--){
    int n;
    cin >> n;
    long long sum = 0;

    sum += n * ((n)*(n-1));

    cout << '\t' << sum << '\n';
  }
}
