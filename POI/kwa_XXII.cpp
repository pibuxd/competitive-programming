#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define all(x) x.begin(), x.end()

int n, mxn = 1e18;
vector<int> excl = {2, 3, 6, 7, 8, 11, 12, 15, 18, 19, 22, 23, 24, 27, 28, 31, 32, 33, 43, 44, 47, 48, 60, 67, 72, 76, 92, 96, 108, 112, 128};
vector<int> lim;

int przer(int x){
  int res = 0;
  int i = 1;
  while(lim[i] <= x){
    res += lower_bound(all(excl), lim[i] - lim[i-1]) - excl.begin();
    i++;
  }

  if(lim[i-1] == x)
    return res;
  int mxadd = lower_bound(all(excl), lim[i] - lim[i-1]) - excl.begin();
  int added = lower_bound(all(excl), lim[i] - x) - excl.begin();
  // cout << added << " -- \n";
  res += mxadd - added;
  return res;
}

bool isexcl(int x){
  if(binary_search(all(excl), x) ||
  binary_search(all(excl), *lower_bound(all(lim), x) - x))
    return true;
  else
    return false;
}

int k(int x){
  if(binary_search(all(excl), x)) 
    return 0;

  auto it = lower_bound(all(lim), x);
  int dist = *it - x;
  int res = it-lim.begin();
  if(!binary_search(all(excl), dist))
    return res;
  
  if(isexcl(x - (res+1)*(res+1)))
    return res+2;
  else
    return res+1;
}

signed main(){
  fastio;
  cin >> n; 
  // n = 30;

  
  for(int sum = 0, pot = 1; sum-(pot*pot) <= 1e18; sum += pot*pot, pot++)
    lim.push_back(sum);
  // cout << lim.size() << "\n";
  // cout << lim.back() << "\n";
  // for(int li : lim) cout << li << " "; cout << "\n";
  // lim = 0 1 5 14 30 55 91 140 204 285 385 506 650 819 ...

  int kn = k(n);
  if(!kn)
    cout << "- ";
  else
    cout << kn << " ";
  cout << przer(n) << "\n";
}