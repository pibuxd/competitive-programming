#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define dlg (r-l+1)

int n, spos;
vector<int> a;

int get_sum(int l, int r){
  vector<int> v(dlg+1);
  for(int i = l; i <= r; i++)
    v[i-l+1] = a[i];
  
  sort(v.begin(), v.end());
  int medx2;
  if(dlg % 2 == 0)
    medx2 = v[dlg/2] + v[dlg/2+1];
  else
    medx2 = 2 * v[dlg/2 + 1];
  
  return dlg + medx2;
}

int main(){
  fastio;
  cin >> n;
  int w = 2*n+1;
  cout << w << " ";
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  spos = 0;
  
  for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j++)
      if(get_sum(i, j) == w)
        spos++;

  cout << spos << "\n";
}