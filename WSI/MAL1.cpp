#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

int n;

struct Odcinek {
  int x1, y1, x2, y2;

  void create(int _x1, int _y1, int _x2, int _y2){
    x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2;
    if(x1 > x2 || (x1 == x2 && y1 > y2)){
      swap(x1, x2);
      swap(y1, y2);
    }
  }
};

int sign(int x){
  if(x == 0) return 0;
  if(x < 0) return -1;
  return 1;
}

int det(int x1, int y1, int x2, int y2, int x3, int y3){
  return x1*y2 + x2*y3 + x3*y1 - x3*y2 - x1*y3 - x2*y1;
}

bool wsp(int x1, int y1, int x2, int y2, int x3, int y3){
  if(det(x1, y1, x2, y2, x3, y3) != 0)
    return false;
  return (min(x1, x2) <= x3 && x3 <= max(x1, x2) && min(y1, y2) <= y3 && y3 <= max(y1, y2));
}

bool czy_przec(Odcinek A, Odcinek B){
  if(wsp(A.x1, A.y1, A.x2, A.y2, B.x1, B.y1) || wsp(A.x1, A.y1, A.x2, A.y2, B.x2, B.y2) ||
     wsp(B.x1, B.y1, B.x2, B.y2, A.x1, A.y1) || wsp(B.x1, B.y1, B.x2, B.y2, A.x2, A.y2))
    return true;
  return ((sign(det(A.x1, A.y1, A.x2, A.y2, B.x1, B.y1)) != sign(det(A.x1, A.y1, A.x2, A.y2, B.x2, B.y2))) &&
          (sign(det(B.x1, B.y1, B.x2, B.y2, A.x1, A.y1)) != sign(det(B.x1, B.y1, B.x2, B.y2, A.x2, A.y2)))
         );
}

vector<Odcinek> odcv;
vector<int> vis;

int bfs(int start, int nr){ // licze przeciecia (W) i odcinki ktore sie przecinaja (K) w spojnej
  int W = 0, K = 0;
  queue<int> Q;
  Q.push(start);
  vis[start] = nr;
  
  while(!Q.empty()){
    K++;
    int v = Q.front();
    Q.pop();

    for(int x = 1; x <= n; x++){
      if(x == v || !czy_przec(odcv[v], odcv[x])) continue;
      W++;
      if(vis[x] != nr){
        vis[x] = nr;
        Q.push(x);
      }
    }
  }

  W /= 2;
  return (W - K + 1);
}

signed main(){
  fastio;
  cin >> n;
  
  odcv.resize(n+1);
  vis.assign(n+1, 0);

  for(int i = 1; i <= n; i++){
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    odcv[i].create(x1, y1, x2, y2);
  } 
  
  int sum = 1, nr = 0;
  for(int i = 1; i <= n; i++)
    if(!vis[i])
      sum += bfs(i, ++nr);

  cout << sum << "\n";
}
