#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, INF = 1e8;
array<int, 2> P, K;
vector<vector<char>> a;
vector<vector<int>> dp, dk; // dist od (p,k)
vector<vector<vector<int>>> DPP, DPK; // dp od (p,k)

bool e(int i, int j, const vector<vector<int>> &d, const vector<vector<char>> &A){ // ok
  return (1 <= i && i <= n && 1 <= j && j <= n && d[i][j] == INF && A[i][j] != 'X' && A[i][j] != '#');
}

void bfsd(array<int, 2> &start, vector<vector<int>> &d, vector<vector<char>> &A){ // ok
  queue<array<int, 2>> Q;
  Q.push(start);
  d[start[0]][start[1]] = 0;

  while(!Q.empty()){
    auto v = Q.front();
    Q.pop();

    if(e(v[0]+1, v[1], d, A)){
      Q.push({v[0]+1, v[1]});
      d[v[0]+1][v[1]] = d[v[0]][v[1]] + 1;
    }
    if(e(v[0], v[1]+1, d, A)){
      Q.push({v[0], v[1]+1});
      d[v[0]][v[1]+1] = d[v[0]][v[1]] + 1;
    }
    if(e(v[0]-1, v[1], d, A)){
      Q.push({v[0]-1, v[1]});
      d[v[0]-1][v[1]] = d[v[0]][v[1]] + 1;
    }
    if(e(v[0], v[1]-1, d, A)){
      Q.push({v[0], v[1]-1});
      d[v[0]][v[1]-1] = d[v[0]][v[1]] + 1;
    }
  }
}

bool e2(int i, int j, const vector<vector<char>> &A){ // ok
  return (1 <= i && i <= n && 1 <= j && j <= n && A[i][j] != 'X');
}

bool e3(int I, int J, int i, int j, const vector<vector<int>> &DS){ // ok
  return (1 <= i && i <= n && 1 <= j && j <= n && 
          1 <= I && I <= n && 1 <= J && J <= n &&
          DS[I][J] == DS[i][j] + 1);
}

char ju(array<int, 2> &PK, const vector<vector<int>> &DS){ // ok
  if(e3(PK[0], PK[1], PK[0]-1, PK[1], DS)){ // G (D)
    PK[0]--;
    return 'D';
  }
  if(e3(PK[0], PK[1], PK[0]+1, PK[1], DS)){ // D (G)
    PK[0]++;
    return 'G';
  }
  if(e3(PK[0], PK[1], PK[0], PK[1]-1, DS)){ // L (P)
    PK[1]--;
    return 'P';
  }
  if(e3(PK[0], PK[1], PK[0], PK[1]+1, DS)){ // P (L)
    PK[1]++;
    return 'L';
  }
  return 'X';
}

vector<char> droga(array<int, 2> &B){ // ok
  vector<vector<char>> A = a;
  int o = B[1];
  while(e2(B[0], o, a)){
    A[B[0]][o] = '.';
    o--;
  }
  o = B[1];
  while(e2(B[0], o, a)){
    A[B[0]][o] = '.';
    o++;
  }
  o = B[0];
  while(e2(o, B[1], a)){
    A[o][B[1]] = '.';
    o--;
  }
  o = B[0];
  while(e2(o, B[1], a)){
    A[o][B[1]] = '.';
    o++;
  }
  vector<vector<int>> DS(n+2, vector<int>(n+2, INF));
  bfsd(P, DS, A);
  //cout << DS[K[0]][K[1]] << "\n";

  vector<char> dro;
  array<int, 2> PK = K;
  while(PK[0] != P[0] || PK[1] != P[1])
    dro.push_back(ju(PK, DS));
  reverse(all(dro));
  return dro;
}

int check(array<int, 2> B){
  return (min({
      DPP[1][B[0]][B[1]],
      DPP[2][B[0]][B[1]],
      DPP[3][B[0]][B[1]],
      DPP[4][B[0]][B[1]] 
  }) + min({
      DPK[1][B[0]][B[1]],
      DPK[2][B[0]][B[1]],
      DPK[3][B[0]][B[1]],
      DPK[4][B[0]][B[1]]
  }));
}

void preDP(vector<vector<vector<int>>> &DP, vector<vector<int>> &d){
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){ // L
      if(a[i][j] == 'X') DP[1][i][j] = INF;
      else DP[1][i][j] = min({d[i][j]-1, DP[1][i][j-1], d[i-1][j], d[i+1][j], d[i][j-1], d[i][j+1]}) + 1;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = n; j >= 1; j--){ // P
      if(a[i][j] == 'X') DP[2][i][j] = INF;
      else DP[2][i][j] = min({d[i][j]-1, DP[2][i][j+1], d[i-1][j], d[i+1][j], d[i][j-1], d[i][j+1]}) + 1;
    }
  }
  for(int j = 1; j <= n; j++){
    for(int i = 1; i <= n; i++){ // G
      if(a[i][j] == 'X') DP[3][i][j] = INF;
      else DP[3][i][j] = min({d[i][j]-1, DP[3][i-1][j], d[i-1][j], d[i+1][j], d[i][j-1], d[i][j+1]}) + 1;
    }
  }
  for(int j = 1; j <= n; j++){
    for(int i = n; i >= 1; i--){ // D
      if(a[i][j] == 'X') DP[4][i][j] = INF;
      else DP[4][i][j] = min({d[i][j]-1, DP[4][i+1][j], d[i-1][j], d[i+1][j], d[i][j-1], d[i][j+1]}) + 1;
    }
  }
}

int main(){
  fastio;
  cin >> n;

  a.resize(n+1, vector<char>(n+1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
      if(a[i][j] == 'P') P = {i, j};
      else if(a[i][j] == 'K') K = {i, j};
    }
  }

  dp = dk = vector<vector<int>>(n+2, vector<int>(n+2, INF));
  bfsd(P, dp, a);
  bfsd(K, dk, a);

  DPP = DPK = vector<vector<vector<int>>>(5, vector<vector<int>>(n+2, vector<int>(n+2, INF)));
  preDP(DPP, dp);
  preDP(DPK, dk);

  int ilr = INF;
  array<int, 2> B;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(a[i][j] != 'X'){
        int r = check({i, j});
        if(r < ilr)
          ilr = r, B = {i, j};
      }

  if(ilr == INF){
    cout << "NIE\n";
    return 0;
  }
  cout << ilr << "\n" << B[0] << " " << B[1] << "\n";
  vector<char> dro = droga(B);
  for(char x : dro) cout << x;
  cout << "\n";
}
