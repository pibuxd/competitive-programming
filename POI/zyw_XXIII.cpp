// MST
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int m, n, N, NE, sumC, sumT;
vector<int> par, siz;
vector<array<int, 3>> C, T; // {a, b, nr}
vector<bool> tak;

int find_set(int v){
  if(par[v] == v) return v;
  return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
  a = find_set(a), b = find_set(b);
  if(a == b) return;
  if(siz[a] < siz[b]) swap(a, b);
  par[b] = a, siz[a] += siz[b];
}

int main(){
  fastio;
  cin >> m >> n;
  
  sumC = sumT = 0;
  NE = m*(n-1)+n*(m-1);
  N = (n+1)*(m+1);
  par.resize(N+1);
  siz.resize(N+1);
  tak.resize(NE+1);
  
  for(int i = 1; i <= N; i++)
    par[i] = i, siz[i] = 1;

  int k = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n-1; j++){
      char c; cin >> c;
      int a = (i-1)*(n+1)+j+1, b = a+n+1;
      k++;
      if(c == 'C') C.push_back({a, b, k});
      else T.push_back({a, b, k});
    }
  }

  for(int i = 1; i <= m-1; i++){
    for(int j = 1; j <= n; j++){
      char c; cin >> c;
      int a = (i)*(n+1)+j, b = a+1;
      k++;
      if(c == 'C') C.push_back({a, b, k});
      else T.push_back({a, b, k});
    }
  }
  
  for(int i = 1; i <= n; i++)
    union_set(i, i+1),
    union_set(m*(n+1)+i, m*(n+1)+i+1);

  for(int i = 1; i <= m; i++)
    union_set((i-1)*(n+1)+1, i*(n+1)+1),
    union_set((i-1)*(n+1)+n+1, i*(n+1)+n+1);

  for(auto [a, b, c] : C){
    if(find_set(a) != find_set(b)){
      union_set(a, b);
      sumC++;
      tak[c] = true;
    }
  }
  for(auto [a, b, c] : T){
    if(find_set(a) != find_set(b)){
      union_set(a, b);
      sumT++;
      tak[c] = true;
    }
  }
  
  cout << sumT+sumC << " " << sumC << "\n";
  k = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n-1; j++)
      cout << (tak[++k] ? 'Z' : '.');
    cout << "\n";
  }
  
  for(int i = 1; i <= m-1; i++){
    for(int j = 1; j <= n; j++)
      cout << (tak[++k] ? 'Z' : '.');
    cout << "\n";
  }
}
