#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;

vector<int> foo(vector<int> a, unordered_set<int> zost){
  if(zost.empty()) return a;

  for(int k = 1; k <= n; k++){
    if(!zost.count(k)) continue;

    zost.erase(zost.find(k));

    for(int i = 1; i+k <= 2*n; i++){
      if(!a[i] && !a[i+k]){
        a[i] = a[i+k] = k;

        vector<int> _a = foo(a, zost);
        if(!_a.empty()) return _a;

        a[i] = a[i+k] = 0;
      }
    }

    zost.insert(k);
  }

  if(!zost.empty())
    return vector<int>();
}

int main(){
  fastio;
  cin >> n;
  unordered_set<int> zost;
  for(int i = 1; i <= n; i++) zost.insert(i);

  vector<int> a(2*(n+1));

  a = foo(a, zost);
  if(a.empty()){
    cout << "NIE";
    return 0;
  }

  cout << "TAK\n";
  for(int i = 1; i <= 2*n; i++)
    cout << a[i] << " ";
}