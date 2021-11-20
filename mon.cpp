#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n;
vector<array<int, 3>> f, in;

int max_start(int time, int end){
  // dzien kiedy trzeba najpozniej zaczac
  return end - time + 1;
}

bool cmp_array(array<int, 3> a, array<int, 3> b){
  return a[1] < b[1];
}

bool cmp_array_ans(array<int, 2> a, array<int, 2> b){
  return a[0] < b[0];
}

struct cmp_pq {
  bool operator()(array<int, 2> a, array<int, 2> b){
    return a[0] < b[0];
  }
};

int main(){
  fastio;
  cin >> n;
  f.resize(n);

  for(int i = 0; i < n; i++){
    cin >> f[i][0] >> f[i][1];
    f[i][2] = i;
  }
  in = f;

  sort(all(f), cmp_array);

  // cout << "\n";
  // for(int i = 0; i < n; i++){
  //   cout << f[i][0] << " " << f[i][1] << " " << f[i][2]+1 << "\n";
  // }
  // cout << "\n";

  priority_queue<array<int, 2>, vector<array<int, 2>>, cmp_pq> pq; // dlg, numer filmu

  int x = 1;
  for(int i = 0; i < n; i++){
    if(max_start(f[i][0], f[i][1]) >= x){
      pq.push({f[i][0], i});
      x += f[i][0];
    }
    else{
      if(!pq.empty()){
        auto t = pq.top();
        // cout << "what?: " << t[0] << " vs " << f[i][0] << "\n";
        if(t[0] > f[i][0]){
          x -= t[0];
          x += f[i][0];
          pq.pop();
          pq.push({f[i][0], i});                    
        }
      }
    }
  }

  vector<array<int, 2>> ans;
  while(!pq.empty()){
    // cout << pq.top()[0] << " " << f[pq.top()[1]][2]+1 << "\n";
    auto t = pq.top();
    ans.push_back({f[t[1]][1], f[t[1]][2]});
    pq.pop();
  }
  // cout << "\n";

  sort(all(ans), cmp_array_ans);
  int l = 1;
  cout << ans.size() << "\n";
  for(auto a : ans){
    cout << a[1]+1 << " " << l << "\n";
    // if(l + in[a[1]][0] - 1 > in[a[1]][1]) {cout << "NOO"; break;}
    l += in[a[1]][0];
  }
}