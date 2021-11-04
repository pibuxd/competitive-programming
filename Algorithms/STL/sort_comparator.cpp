// * sort with custom comparator
// if size of two strings is equal -> sort lexicographically
// else -> sort strings ascending by size
#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> a;

bool comp(string &a, string &b){
  int as = a.size();
  int bs = b.size();

  if(as == bs)
    return a < b;
  else
    return as < bs;
}

int main(){
  cin >> n;
  a.assign(n, "");

  for(int i = 0; i < n; i++)
    cin >> a[i];

  sort(a.begin(), a.end(), comp);
  for(auto s : a)
    cout << s << "\n";
}