#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

const int MXN = 111;
vector<int> d, a;
int n;

auto find_max(int m){
  pair<int, int> maximum = {MXN, MXN};
  int maximum1 = -1, maximum2 = -1;

  for(int i = 1; i <= n; i++){
    if(d[a[i]] >= 0) continue;

    if(i < m){
      if(maximum1 < a[i]){
        maximum.first = i;
        maximum1 = a[i];
      }
    } else{
      if(maximum2 < a[i]){
        maximum.second = i;
        maximum2 = a[i];
      }
    }
  }

  return maximum;
}

void solve(int start){
  int depth = 0;
  queue<int> Q;
  Q.push(start);

  while(!Q.empty()){
    depth++;
    int m = Q.front();
    Q.pop();

    auto maximum = find_max(m);

    if(maximum.second != MXN){
      d[a[maximum.second]] = depth; 
      Q.push(maximum.second);
    }

    if(maximum.first != MXN){
      d[a[maximum.first]] = depth;
      Q.push(maximum.first);
    } 
  }
}

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    cin >> n;

    d = a = vector<int>(101, -1);

    for(int i = 1; i <= n; i++){
      cin >> a[i];
    }

    vector<int>::iterator maximum = max_element(a.begin(), a.end());
    int m = maximum - a.begin();
    int value = *maximum;
    d[value] = 0;
    //cout << find_max(m).first << " and " << find_max(m).second << " \t";
    solve(m);

    for(int i = 1; i <= n; i++){
      cout << d[a[i]] << ' ';
    }

    cout << "\n";
  }
}