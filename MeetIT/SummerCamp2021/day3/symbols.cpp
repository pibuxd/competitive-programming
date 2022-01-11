#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
string s;
vector<int> state;

bool compare_vec(vector<int> &a, vector<int> &b){
  for(int i = 0; i <= 2000002; i++)
    if(a[i] != b[i])
      return false;

  return true;
}

void process(vector<int> &x, int it, int jt){
  int p = 0;

  for(int i = it; i <= jt; i++){
    if(s[i] == '+'){
      if(p >= 0)
        x[i]++;
      else
        x[1e6+1-i]++;
    }
    else if(s[i] == '-'){
      if(p >= 0)
        x[i]--;
      else
        x[1e6+1-i]--;
    }
    else if(s[i] == '>'){
      p++;
    }
    else if(s[i] == '-'){
      p--;
    }
  }
}

int main(){
  fastio;
  cin >> n >> s;

  state.resize(2000003);
  process(state, 0, 2000002);

  int ans = 0;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      vector<int> temp(2000003);
      process(temp, i, j);
      if(compare_vec(state, temp))
        ans++;
    }
  }

  cout << ans;
}