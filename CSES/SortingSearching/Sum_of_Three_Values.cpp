// * 2P (Two poiners)
// * also usage of multimap
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, x;
vector<int> a;
multimap<int, int> m;

int main(){
  fastio;
  cin >> n >> x;

  a.resize(n+1);
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    m.insert({a[i], i});
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      if(i == j) continue;
      int searched = x-a[i]-a[j];
      if(!searched) continue;

      auto it = m.lower_bound(searched);

      again:
      if(it->first == searched && it->second != i && it->second != j){
        cout << i << " " << j << " " << it->second;
        return 0;
      }
      else if(it->first == searched && (it->second == i || it->second == j)){
        it++;
        if(it != m.end())
          goto again;
      } 
    }

  cout << "IMPOSSIBLE";
}