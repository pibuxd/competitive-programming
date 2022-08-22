#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

long long n;

int main(){
  fastio;
  cin >> n;

  indexed_set s;
  long long sum = 0;

  for(int i = 1; i <= n; i++){
    long long a; cin >> a;
    sum += s.size()-s.order_of_key({i, 0});
    s.insert({a, i});
  }

  cout << sum;
}
