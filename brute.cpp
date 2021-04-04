#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int shortest_period(string &s){
  int n = s.size();

  string pattern = "";
  bool check = true;

  for(int i = 0; i <= (n+1)/2; i++, check = true, pattern = ""){
    for(int it = 0; it <= i; it++){
      pattern += s[it];
    }
    //cout << pattern << " ";

    for(int it = 0; it < n; it++){
      if(pattern[it%(i+1)] != s[it]){
        //cout << it%(i+1) << "," << it << " ";
        check = false;
      }
    }

    if(check){ // ok
      return n/(i+1);
    }
  }

  return 1;
}

int main(){
  fastio;

  int t;
  cin >> t;
  
  while(t--){
    string s;
    cin >> s;
    cout << shortest_period(s) << "\n";
  }
}