#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int k = 0, d = 0;

    map<pair<int, int>, int> licz;

    for(int i = 0; i < n; i++){
      if(s[i] == 'D') d++;
      else k++;
      cout << ++licz[{k/gcd(k,d), d/gcd(k,d)}] << " ";
    }

    cout << "\n";
  }
}