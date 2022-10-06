#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, x, y;
vector<int> a, as;
unordered_map<int, int> M;

int main(){
  fastio;
  cin >> n;
  a.resize(n+1);

  for(int i = 1; i <= n; i++) cin >> a[i];

  as = a;
  sort(all(as));
  for(int i = 1; i <= n; i++)
    M[as[i]] = i;   
  
  x = 0;
  for(int i = 1; i <= n; i++)
    if(abs(M[a[i]] - i) % 2 == 1)
      x++;

  cout << x << "\n";
}
