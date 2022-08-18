// to debug :(
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<char> a;
vector<int> pref;
vector<bool> vis;
stack<vector<int>> ans;

void add(int l, int r){
  vector<int> v;
  while(l <= r && !vis[l]){
    v.push_back(l);
    vis[l] = true;
    l++;
  }
  while(l <= r && !vis[r]){
    v.push_back(r);
    vis[r] = true;
    r--;
  }
  sort(v.begin(), v.end());
  ans.push(v);
}

int main(){
  fastio;
  cin >> n >> k;

  a.resize(n+1);
  vis.resize(n+1);
  pref.resize(n+1);

  for(int i = 1; i <= n; i++)
    cin >> a[i];
  for(int i = 1; i <= n; i++)
    pref[i] = pref[i-1] + (a[i] == 'b' ? 1 : -k);
  
  stack<int> s;
  set<int> onstack;

  for(int i = 0; i <= n; i++){
    if(onstack.count(pref[i])){
      while(pref[s.top()-1] != pref[i]){
        onstack.erase(pref[s.top()-1]);
        s.pop();
      }
      add(s.top(), i);
      s.pop();
    }
    
    s.push(i+1);
    onstack.insert(pref[i]);
  }

  while(!ans.empty()){
    for(int i : ans.top())
      cout << i << " ";
    cout << "\n";
    ans.pop();
  }
}