// * The main idea is sorting in descending order or answering queries from rightmost to leftmost
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

bool comp(const array<int, 3> &a1, const array<int, 3> &a2){
  return a1[1] == a2[1] ? a1[0] < a2[0] : a1[1] < a2[1];
}

int main(){
  fastio;
  int n, q;
  cin >> n >> q;
  vector<int> a(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  vector<array<int, 3>> qr(q+1);
  for(int i = 1; i <= q; i++){
    cin >> qr[i][0] >> qr[i][1];
    qr[i][2] = i;
  }
  

  sort(all(qr), comp);
  
  vector<int> ans(q+1);
  map<int, int> w; // waiting
  indexed_set s;
  int r = 0;
  for(int i = 1; i <= q; i++){
    int qs = qr[i][0], qe = qr[i][1], qi = qr[i][2];

    while(r < qe){
      r++;

      s.insert(r);
      if(w[a[r]])
        s.erase(w[a[r]]);
      
      w[a[r]] = r;
    }

    ans[qi] = s.size() - s.order_of_key(qs);
  }  

  for(int i = 1; i <= q; i++)
    cout << ans[i] << "\n";
}