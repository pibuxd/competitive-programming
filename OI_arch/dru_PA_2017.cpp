#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  string n; cin >> n; vector<int> v;
  for(int i = 0; i < n.size(); i++){
    v.push_back(n[i]-48);
  }
  for(int i = 0; i < n.size(); i++){
    
    for(int i = 0; i < v[i]; i++){
      if(v[i]%i == 0) goto but;
    }

  }
  cout << "TAK";
  nonprime:
  cout << "NIE";
}
