#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()
#define int long long

int x;
vector<int> a;

void dziel(int n){
  a.assign({1, n});
  int sqn = sqrt(n);
  
  for(int i = 2; i <= sqn; i++){
    if(n % i == 0){
      a.push_back(i);
      if(n / i != i)
        a.push_back(n/i);
    }
  }
}

signed main(){
  fastio;
  cin >> x;
  if(x == 1){
    cout << 1;
    return 0;
  }
  dziel(x);

  sort(all(a));
  for(int i : a)
    cout << i << " ";
}
