// autor - Piotr Bublik
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

struct ulamek { // a / b to ulamek zwykly
  int a, b;
  
  ulamek(int _a = -1, int _b = 1){
    a = _a, b = _b;
  }

  ulamek operator / (const ulamek ul) const { // calkowita / ulamek
    return {a * ul.b, ul.a};
  }
  
  ulamek operator - (const ulamek ul) const {
    return {a*ul.b - ul.a*b, b*ul.b};
  }

  bool operator < (const ulamek ul) const {
    int c1 = a/b, a1 = a%b, b1 = b;
    int c2 = ul.a/ul.b, a2 = ul.a%ul.b, b2 = ul.b;
    if(c1 == c2)
      return a1 * b2 < a2 * b1;
    return c1 < c2;
  }

  bool operator >= (const ulamek ul) const {
    int c1 = a/b, a1 = a%b, b1 = b;
    int c2 = ul.a/ul.b, a2 = ul.a%ul.b, b2 = ul.b;
    if(c1 == c2)
      return a1 * b2 >= a2 * b1;
    return c1 >= c2;
  }
  
  bool operator != (const ulamek ul) const {
    return a*ul.b != ul.a*b;
  }
};

struct wagon {
  int Lid, Rid;
  int x, d;
  ulamek v;

  wagon(int _Lid = 0, int _Rid = 0, int _x = 0, int _d = 0, ulamek _v = ulamek()){
    Lid = _Lid, Rid = _Rid, x = _x, d = _d, v = _v;
  }
};

int n, D, W, M;
ulamek V;
vector<wagon> wagony;

ulamek wagdog(const wagon &w1, const wagon &w2){
  return ulamek(w2.x - w1.x - w2.d, 1) / (w1.v - w2.v);
}

ulamek tL(const wagon &w1){
  return ulamek(w1.x + D, 1) / (V - w1.v);
}

ulamek tP(const wagon &w2){
  return ulamek(w2.x - w2.d, 1) / (V - w2.v);
}

vector<pair<ulamek, int>> dogkol; // chronologicznie posortowane dogonienia wagonow
vector<ulamek> vecdog; // kiedy wagon dogoni prawego
int it;

void initdog(){
  priority_queue<pair<ulamek, int>, vector<pair<ulamek, int>>, greater<pair<ulamek, int>>> Q; 
  // {t kiedy sie dogonia [ulamek], idwagonu}

  vecdog.resize(n+1);
  vector<wagon> __wagony = wagony;
  vector<ulamek> val(n+1);

  for(int i = 1; i < n; i++) 
    if(__wagony[i+1].v < __wagony[i].v){
      val[i] = wagdog(__wagony[i], __wagony[i+1]);
      Q.push({val[i], i});
    }
  
  while(!Q.empty()){ // podobna technika do dijksty
    auto [t, c] = Q.top();
    Q.pop();
    if(val[c] != t) continue;

    dogkol.push_back({t, c});
    vecdog[c] = t;

    int wagL = __wagony[c].Lid, wagR = __wagony[c].Rid;
    __wagony[wagL].Rid = wagR;
    __wagony[wagR].Lid = wagL;
    __wagony[wagR].d += __wagony[c].d;
    val[c] = ulamek();

    if(wagL >= 1 && __wagony[wagR].v < __wagony[wagL].v){
      val[wagL] = wagdog(__wagony[wagL], __wagony[wagR]);
      Q.push({val[wagL], wagL});
    }
  }
  it = 0;
}

void dogto(ulamek tmax){
  while(it < dogkol.size() && dogkol[it].first < tmax){
    auto [t, c] = dogkol[it];
    int wagL = wagony[c].Lid, wagR = wagony[c].Rid;
    wagony[wagL].Rid = wagR;
    wagony[wagR].Lid = wagL;
    wagony[wagR].d += wagony[c].d;
    it++;
  }
}

signed main(){
  fastio;
  cin >> n >> D >> W >> M;
  V = ulamek(W, M);
  wagony.resize(n+1);

  for(int i = 1; i <= n; i++){
    int x, d, w, m; cin >> x >> d >> w >> m;
    wagony[i] = wagon(i-1, i+1, x, d, ulamek(w, m));
  }

  initdog();
  int sum = 1;
  
  for(int i = 1; i < n; i++){
    ulamek tl = tL(wagony[i]);
    if(vecdog[i] < tl && vecdog[i] != ulamek()) continue;

    dogto(tl);
    
    ulamek tp = tP(wagony[wagony[i].Rid]);
    if(tp >= tl) sum++;
  }
  
  cout << sum << "\n";
}
