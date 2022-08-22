#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<pair<long long, long long>, null_type, greater<pair<long long, long long>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

long long n;

int main(){
  fastio;
  cin >> n;

  indexed_set s;
  long long sum = 0;

  for(long long i = 1; i <= n; i++){
    long long a; cin >> a;

    sum += s.order_of_key({min(a, i)-1, 0});
    s.insert({a, i});
  }

  cout << sum;
}
