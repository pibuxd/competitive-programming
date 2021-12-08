#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> a;

int solve(){
  vector<array<int, 3>> czasy;
  int last = 1, wypelnione = 0;

  for(int i = 1; i <= n; i++){
    wypelnione += a[i];
    
    if(a[i] == 1 || i == n){
      int dlg = (i-1) - last + 1;
      if(i == n && a[n] == 0)
        dlg++;

      if(dlg > 0){
        if((last == 1 && a[1] == 0) || a[i] == 0)
          czasy.push_back({dlg, -1, dlg});
        else
          czasy.push_back({(dlg / 2) + (dlg % 2), -2, dlg});
      }

      last = i + 1;
    }
  }

  sort(czasy.rbegin(), czasy.rend());

  // for(auto t : czasy)
    // cout << "{ " << t[0] << " , " << t[1] << " , " << t[2] << " } ";

  int nr_ruchu = 0;
  for(auto t : czasy){
    // cout << nr_ruchu << ": " << "{ " << t[0] << " , " << t[1] << " , " << t[2] << " } --> before: " << wypelnione << " after: ";

    if(nr_ruchu >= t[0]){
      wypelnione += t[2];
      // cout << wypelnione << "\n";
      continue;
    }
    else
      wypelnione += -t[1] * nr_ruchu;
    
    if(-t[1] == 2){
      if(nr_ruchu + 1 == t[0]){
        nr_ruchu++;
        if(t[2] % 2 == 0)
          wypelnione++;
      }
      else
        nr_ruchu += 2, wypelnione++;

    } else{
        nr_ruchu++;
    }
    // cout << wypelnione << "\n";
  }

  return wypelnione;
}

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> n >> s;
    a.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
      a[i] = (s[i-1] == '1') ? 1 : 0;
    cout << solve() << "\n";
  }
}