#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k, ai, done, cap;
vector<int> team, skl, skr;
vector<pair<int, int>> a;

void fcap(){
  cap = (cap == 0 ? 1 : 0);
}

pair<int, int> mxa(){
  while(ai < n && team[a[ai].second] != -1)
    ai++;
  return a[ai];
}

int main(){
  fastio;
  cin >> n >> k;

  ai = 0;
  a.assign(n, {});
  team.assign(n, -1);
  skl.assign(n, -1);
  skr.assign(n, n);

  for(int i = 0; i < n; i++){
    int x; cin >> x;
    a[i] = {x, i};
  }
  sort(a.rbegin(), a.rend());

  done = 0, cap = 0;
  
  while(done < n){
    pair<int, int> mx = mxa();
    team[mx.second] = cap;
    // cout << mx.first << ": " << mx.second << " ";

    int l = 0, li = mx.second;
    while(l < k && li > 0){
      while(l < k && li > 0 && team[li-1] == -1){
        li--;
        team[li] = cap;
        // cout << li << " ";
        l++;
      }
      if(l < k && li > 0)
        li = skl[li-1];
    }
    int r = 0, ri = mx.second;
    while(r < k && ri < n-1){
      while(r < k && ri < n-1 && team[ri+1] == -1){
        ri++;
        team[ri] = cap;
        // cout << ri << " ";
        r++;
      }
      if(r < k && ri < n-1)
        ri = skr[ri+1];
      // cout << "'" << ri << " ";
    }

    skl[ri] = li;
    skr[li] = ri;
    // cout << "{ " << li << ", " << ri << "} ";
    done += 1 + r + l;
    fcap();
    // cout << "\n";
  }

  for(int i = 0; i <= n-1; i++) cout << team[i] << " ";
}