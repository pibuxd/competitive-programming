// * Order Statistic Tree (ordered set/indexed set)
// * policy based data structure
// * tree-based container O(log(n))
// about1: https://codeforces.com/blog/entry/11080
// about2: https://codeforces.com/blog/entry/11080
// example problems:
// https://cses.fi/problemset/task/1749
// https://cses.fi/problemset/task/1144
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

int main(){
  indexed_set s;
  s.insert(3);
  s.insert(6);
  s.insert(7);
  s.insert(1);

  // returns an iterator to the element at a given position
  auto x = *s.find_by_order(1); 
  cout << x << "\n"; // 3

  // returns the position of a given element
  auto y = s.order_of_key(3);
  cout << y << "\n"; // 1

}