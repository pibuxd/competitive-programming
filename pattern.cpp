#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

using ll=long long;
using pll=pair<ll, ll>;
 
struct node {
  ll sum=0, incr=0, all=0;
};
 
const int mxN=2e5+1;
int n, q;
ll a[mxN];
node seg[mxN*4];
 
void build(int v=1, int l=0, int r=n-1) {
  if (l==r) {
      seg[v].sum=a[l];
      return;
  }
  int mid=(l+r)/2;
  build(v*2, l, mid);
  build(v*2+1, mid+1, r);
  seg[v].sum=max(seg[v*2].sum,seg[v*2+1].sum);
}
 
void push(int v, int l, int r) {
  if (seg[v].all)
      seg[v].sum=(r-l+1)*seg[v].all;
  seg[v].sum+=(r-l+1)*seg[v].incr;

  if (l!=r) {
      if (seg[v].all) {
          seg[v*2].incr=seg[v*2+1].incr=seg[v].incr;
          seg[v*2].all=seg[v*2+1].all=seg[v].all;
      }
      else {
          seg[v*2].incr+=seg[v].incr;
          seg[v*2+1].incr+=seg[v].incr;
      }
  }
  seg[v].incr=seg[v].all=0;
}
 
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
  if (l>hi || r<lo || l>=n)
      return;
  if (lo>=l && hi<=r) {
      if (x>0)
          seg[v].incr+=x;
      else
          seg[v].all=-x, seg[v].incr=0;
      return;
  }

  push(v, lo, hi);
  int mid=(lo+hi)/2;

  upd(l, r, x, lo, mid, v*2);
  upd(l, r, x, mid+1, hi, v*2+1);

  push(v*2, lo, mid);
  push(v*2+1, mid+1, hi);
  seg[v].sum=max(seg[v*2].sum,seg[v*2+1].sum);
}
 
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
  if (l>hi || r<lo || l>=n)
      return 0;
  push(v, lo, hi);
  if (lo>=l && hi<=r)
      return seg[v].sum;
  int mid=(lo+hi)/2;
  return max(query(l, r, lo, mid, v*2),query(l, r, mid+1, hi, v*2+1));
}
 
int main(){
  cin >> n >> q;

  for(int i = 0; i < n; i++)
    a[i] = 0;

  build();

  while(q--){
    int a, b;
    cin >> a >> b;
    b--;

    int t = 2;
    int x = query(a, a+b);
    cout << x << endl;
    //cout << x;
    upd(a, b, (t==1?1:-1)*(x+1));   
  }
  
  cout << query(1, n);
}