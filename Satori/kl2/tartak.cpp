#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Ciecie {
  int v, l, r;
  bool is;

  bool operator<(const Ciecie& a) const{
    return v < a.v;
  }
};

int n, m;

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int d, n;
    cin >> d >> n;
    vector<Ciecie> a(n);
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      a[i] = {x, x, d - x, true};
    }
    sort(a.begin(), a.end());
    
    int ans = 0;

    for(int temp = 1; temp <= n; temp++){
      int mini = 1e9+1, minit;
      for(int i = 0; i < n; i++){
        if(!a[i].is) continue;
        int df = abs(a[i].l-a[i].r);
        if(df < mini){
          mini = df;
          minit = i;
        }
      }
      a[minit].is = false;
      ans += max(a[minit].l, a[minit].r);

      for(int i = minit-1; i >= 0 && a[i].is; i--){
        a[i].r = a[minit].v - a[i].v;
      }

      for(int i = minit+1; i < n && a[i].is; i++){
        a[i].l = a[i].v - a[minit].v;
      }
    }
    
    cout << ans << "\n";
  }
}