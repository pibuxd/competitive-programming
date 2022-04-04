// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Order Statistic Tree (ordered set/indexed set)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
  fastio;
  int n;
  cin >> n;
  vector<int> p(n+1);
  indexed_set s;

  for(int i = 1; i <= n; i++){
    s.insert(i);
    cin >> p[i];  
  }
  
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;

    auto it = s.find_by_order(x-1);
    int j = *it;

    cout << p[j] << " ";
    s.erase(it);
  }
}