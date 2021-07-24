// * Order Statistic Tree (ordered set/indexed set)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
  fastio;
  const int mxn = 2*1e5+1;
  int n, q;
  cin >> n >> q;
  vector<int> v(n+1);
  indexed_set s;

  for(int i = 1; i <= n; i++){
    cin >> v[i];
    s.insert({v[i], i});
  }

  while(q--){
    char operation;
    int a, b;
    cin >> operation >> a >> b;
    if(operation == '!'){
      s.erase({v[a], a});
      s.insert({b, a});
      v[a] = b;
    } else{
      int ans = s.order_of_key({b, mxn}) - s.order_of_key({a-1, mxn});
      cout << ans << "\n";
    }
  }
}