// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, m;
vector<unordered_map<int, int>> M(17);

void print_map(unordered_map<int, int> &X){
  for(auto a : X) cout << a.first << " x " << a.second << " , ";
}

void sliding_window(string &s, int x){
  // cout << x << ": ";
  if(false){
    // cout << "\n";
    return;
  }
  string b = "";
  for(int i = 0; i < x; i++)
    b += s[i];

  int curr = (int)(bitset<16>(b).to_ullong());
  M[x][curr]++;

  for(int l = 0, r = x-1; r < n-1; l++, r++){
    if(s[l] == '1')
      curr -= 1 << (x-1);
    curr = curr << 1;
    if(s[r+1] == '1')
      curr += 1;

    M[x][curr]++;
  }
  // print_map(M[x]);
  // cout << "\n";
}

void init(string &s){
  for(int i = 1; i <= min(16, n); i++)
    sliding_window(s, i);
}

void sliding_window2(string &s, int a, int x, int op){
  // cout << x << ": ";
  if(false){
    // cout << "\n";
    return;
  }
  string b = "";
  int start = max(a-x+1, 0);
  for(int i = start; i <= start+x-1; i++)
    b += s[i];

  int curr = (int)(bitset<16>(b).to_ullong());
  M[x][curr] += op;
  if(M[x][curr] == 0) M[x].erase(curr);

  for(int l = start, r = start+x-1; l < min(a+x-1, n-1) && r < n-1; l++, r++){
    if(s[l] == '1')
      curr -= 1 << (x-1);
    curr = curr << 1;
    if(s[r+1] == '1')
      curr += 1;

    M[x][curr] += op;
    if(M[x][curr] == 0) M[x].erase(curr);
  }
  // print_map(M[x]);
  // cout << "\n";
}

void update(string &s, int a){
  a--;
  for(int i = 1; i <= min(16, n); i++)
    sliding_window2(s, a, i, -1);

  s[a] = (s[a] == '1') ? '0' : '1';
  // cout << "s = " << s;
  // cout << "\n";
  for(int i = 1; i <= min(16, n); i++)
    sliding_window2(s, a, i, 1);
}

int ans(){
  int x = 1;
  while(x <= 16){
    if(M[x].size() != 1 << x)
      break;
    x++;
  }

  return x;
}

int main(){
  fastio;
  string s;
  cin >> n >> m >> s;
  // cout << '\n';
  init(s);
  cout << ans() << "\n";

  while(m--){
    int a;
    cin >> a;
    update(s, a);
    cout << ans() << "\n";
  }
}