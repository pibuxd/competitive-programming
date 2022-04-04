// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

struct Pkt {
  int x, y;
};

int n, t, T;
vector<int> d, ti;
vector<array<Pkt, 2>> a;
Pkt e, p;

Pkt przesuniecie(){
  Pkt _p = {0, 0};

  T = 0;
  for(int i = 1; i <= n; i++){
    T += d[i];
    ti[i] = T;
    a[i][0] = _p;
    if(i % 4 == 1) _p.y += d[i];      // do gory
    else if(i % 4 == 2) _p.x += d[i]; // w prawo
    else if(i % 4 == 3) _p.y -= d[i]; // w dol
    else if(i % 4 == 0) _p.x -= d[i]; // w lewo
    a[i][1] = _p;
  }

  return _p;
}

int k(int it, int j){ // czas po j pelnych petlach dla pkt a[it][1]
  return (T+n)*j + ti[it] + it-1;
}

int t_meet(int it){ 
  if(it % 4 == 1 || it % 4 == 3){ // pionowa

    if(p.x == 0){
      if(a[it][0].x != e.x) return -1;

      if(it % 4 == 1){
        if(a[it][0].y < e.y && e.y <= a[it][1].y){
          int r = e.y - a[it][0].y;
          int s = r / p.y;
          // cout << s << "X\n";
          if(k(it, s-1) - a[it][1].y - e.y - s * p.y <= t)
            return s;
          else{
            int dif = (s-1)*(T+n) - t;
            int o = dif / (T+n);
            if(dif % (T+n) != 0) o++;
            int _s = s - o;
            return _s;
          }
        }
      } else{
        if(a[it][1].y <= e.y && e.y < a[it][0].y){
          int r = e.y - a[it][0].y;
          int s = r / p.y;
          // cout << s << "X\n";
          if(k(it, s-1) - a[it][1].y - e.y - s * p.y <= t)
            return s;
          else{
            int dif = (s-1)*(T+n) - t;
            int o = dif / (T+n);
            if(dif % (T+n) != 0) o++;
            int _s = s - o;
            return _s;
          }
        }
      }
    }

    int r = e.x - a[it][0].x;
    int j = r / p.x;
    if(r % p.x != 0) return -1;

    // cout << it << " " << r << " " << j << " " << a[it][0].x << "\n";
    if(it % 4 == 1){
      if(a[it][0].y + j*p.y < e.y && e.y <= a[it][1].y + j*p.y)
        return (ti[it] + T*j - abs(a[it][1].y + j*p.y - e.y) + (it + j*n - 1)) ? 1 : -1;
    } else{
      if(a[it][1].y + j*p.y <= e.y && e.y < a[it][0].y + j*p.y)
        return (ti[it] + T*j - abs(a[it][1].y + j*p.y - e.y) + (it + j*n - 1)) ? 1 : -1;
    }

  } else{ // pozioma

    if(p.y == 0){
      if(a[it][0].y != e.y) return -1;

      if(it % 4 == 1){
        if(a[it][0].x < e.x && e.x <= a[it][1].y){
          int r = e.x - a[it][0].x;
          int s = r / p.x;
          // cout << s << "X\n";
          if(k(it, s-1) - a[it][1].x - e.x - s * p.x <= t)
            return s;
          else{
            int dif = (s-1)*(T+n) - t;
            int o = dif / (T+n);
            if(dif % (T+n) != 0) o++;
            int _s = s - o;
            return _s;
          }
        }
      } else{
        if(a[it][1].x <= e.x && e.x < a[it][0].x){
          int r = e.x - a[it][0].x;
          int s = r / p.x;
          // cout << s << "X\n";
          if(k(it, s-1) - a[it][1].x - e.x - s * p.x <= t)
            return s;
          else{
            int dif = (s-1)*(T+n) - t;
            int o = dif / (T+n);
            if(dif % (T+n) != 0) o++;
            int _s = s - o;
            return _s;
          }
        }
      }
    }

    int r = e.y - a[it][0].y;
    int j = r / p.y;
    if(r % p.y != 0) return -1;

    // cout << it << " " << r << " " << j << " " << a[it][1].x + j*p.x << "\n";
    if(it % 4 == 2){
      if(a[it][0].x + j*p.x < e.x && e.x <= a[it][1].x + j*p.x)
        return (ti[it] + T*j - abs(a[it][1].x + j*p.x - e.x) + (it + j*n - 1)) ? 1 : -1;
    } else{
      if(a[it][1].x + j*p.x <= e.x && e.x < a[it][0].x + j*p.x)
        return (ti[it] + T*j - abs(a[it][1].x + j*p.x - e.x) + (it + j*n - 1)) ? 1 : -1;
    }
  }

  return -1;
}

int solve(){
  if(p.x == 0 && p.y == 0) return 69;
  int l = 0;
  if(e.x == 0 && e.y == 0) l++;
  for(int i = 1; i <= n; i++){
    int __t = t_meet(i);
    if(__t >= 0)
      l += __t;
    // cout << __t << "\n";
  }
  return l;
}

signed main(){
  fastio;
  // cout << "\n";
  cin >> n >> t;
  d.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> d[i];
  cin >> e.x >> e.y;

  int _n = n;
  for(int i = 1; n % 4 != 0 || n % _n != 0; i++, n++)
    d.push_back(d[i]);

  // for(int i = 1; i <= n; i++)
  //   cout << d[i] << " ";
  // cout << "\n";

  a.resize(n+1);
  ti.resize(n+1);
  p = przesuniecie();

  // cout << p.x << " " << p.y << "\n";
  // cout << "T: " << T << "\n";
  cout << solve();
}