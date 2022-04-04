// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int n, k, b, d;
vector<int> a;

int main(){
  fastio;
  cin >> n >> k >> b >> d;
  a.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  
  int l = 1, r = 1, nie = 0;
  long long sum = 0, mx_dlg = -1,  mx_start = -1;
  float mx_sr = -1.0;
  sum = a[1];
  nie = (a[1] % k != 0) ? 1 : 0;

  while(r <= n){
    if(nie > b){
      sum -= a[l];
      nie -= (a[l] % k != 0) ? 1 : 0;
      l++;

    } else{
      r++;
      sum += a[r];
      nie += (a[r] % k != 0) ? 1 : 0;
    }
    // cout << l << " " << r << "\n";
    if(nie <= b && sum > 0){
      int curr_dlg = r-l+1, curr_start = l;
      float curr_sr = (float)sum / (float)curr_dlg;

      if(curr_dlg > mx_dlg){
        mx_dlg = curr_dlg, mx_sr = curr_sr, mx_start = l;

      } else if(curr_dlg == mx_dlg && curr_sr > mx_sr){
        mx_sr = curr_sr, mx_start = l;
      }
    }
  }

  // cout << "mx_dlg, mx_sr, mx_start: " << mx_dlg << "; " << mx_sr << "; " << mx_start << "\n";

  if(mx_dlg == -1){
    cout << "NIE\n";
    return 0;
  }

  cout << mx_dlg << "\n";
  cout << setprecision(d) << fixed << mx_sr << "\n";
  for(int i = mx_start; i <= mx_start+mx_dlg-1; i++)
    cout << a[i] << " ";
  cout << "\n";
}