// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n;
vector<int> par, mxiq, mniq, sum;

void make_set(int v, int mass, int iq){
  par[v] = v;
  sum[v] = mass;
  mxiq[v] = mniq[v] = iq;
}

int find_set(int v){
  if(par[v] == v)
    return v;
  return par[v] = find_set(par[v]);
}

void union_sets(int a, int b){
  a = find_set(a);
  b = find_set(b);
  if(a == b) return;

  par[b] = par[a];
  mxiq[a] = max(mxiq[a], mxiq[b]);
  mniq[a] = min(mniq[a], mniq[b]);
  sum[a] = sum[a] + sum[b];
}

int mass(int v){
  return sum[find_set(v)];
}

int iqmax(int v){
  return mxiq[find_set(v)];
}

int iqmin(int v){
  return mniq[find_set(v)];
}

int main(){
  fastio;
  cin >> n;
  par = mxiq = mniq = sum = vector<int>(n+1);

  for(int i = 1; i <= n; i++){
    int a, b;
    cin >> a >> b;
    make_set(i, a, b);
  }

  string query;
  while(cin >> query){
    if(query == "JOIN"){
      int a, b;
      cin >> a >> b;
      union_sets(a, b);
    }
    else if(query == "IQ_MAX"){
      int x;
      cin >> x;
      cout << iqmax(x) << "\n";
    }
    else if(query == "IQ_MIN"){
      int x;
      cin >> x;
      cout << iqmin(x) << "\n";
    }
    else if(query == "MASA"){
      int x;
      cin >> x;
      cout << mass(x) << "\n";
    }
  }
}