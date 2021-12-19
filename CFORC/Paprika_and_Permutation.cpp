#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;

int solve(){
  vector<int> _a = a;
  sort(_a.begin(), _a.end());
  set<int> s;
  for(int i = 1; i <= n; i++)
    s.insert(i);

  int res = 0;

  for(int i = 1; i <= n; i++){
    int f = *s.begin();

    if(_a[i] <= n && s.count(_a[i])){
      s.erase(s.find(_a[i]));
      continue;
    }
    if(_a[i] > 2*f){
      res++;
      s.erase(s.find(f));
    }
  }

  if(!s.empty())
    return -1;

  return res;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
      cin >> a[i]; 
    cout << solve() << "\n";
  }
}