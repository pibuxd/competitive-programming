// * Nearest Smaller Element problem
// * Stack
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> v, ans;

int main(){
  fastio;
  cin >> n;
  v.resize(n+1);
  ans.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> v[i];

  stack<int> S;
  S.push(n);
  for(int i = n-1; i >= 1; i--){
    while(!S.empty()){
      int x = S.top();
      if(v[i] < v[x]){
        S.pop();
        ans[x] = i;
      }
      else
        break;
    }
    S.push(i);
  }


  for(int i = 1; i <= n; i++)
    cout << ans[i] << " ";
}