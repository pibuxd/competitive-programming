// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * Find union + school maths summing two numbers
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

#define int unsigned long long

int k, llen, rlen, n, _n;
vector<int> z, p, idx;
vector<char> l, r;
vector<bool> is1, is0;

int vartoint(char var){
  return (int)var - (int)'a' + 1;
}

void make_set(int v){
  p[v] = v;
}

int find_union(int v){
  if(p[v] == v)
    return v;
  return p[v] = find_union(p[v]);
}

void make_union(int a, int b){
  a = find_union(a);
  b = find_union(b);

  if(a != b){
    is1[a] = is1[b] = (is1[b] || is1[a]);
    is0[a] = is0[b] = (is0[b] || is0[a]);
    p[b] = a;
  }
}

int val(char c){
  return (int)c - (int)'0';
}

char chr(int x){
  return (char)x + (char)'0';
}

bool can_add(string &s, int i){
  return !s.empty() && i <= s.size()-1;
}

void incr(string &s){
  s.push_back('0');
}

int j(int x){
  return x % 10;
}

void add(string &u, string s, int start){
  int i = start;
  int lazy = 0, ile_dod = 1;

  while(true){
    bool incred = false;
    if(!can_add(u, i)){
      incr(u);
      incred = true;
    }

    bool lazed = lazy > 0;
    if(lazy > 0){
      string lazystr = to_string(lazy);
      add(u, lazystr, i);
    }

    lazy = ile_dod = 0;

    int _i = i-start;

    if(!can_add(s, _i)){
      if(incred && !lazed)
        if(!u.empty())
          u.erase(u.end()-1);
      break;
    }

    int v = val(u[i]) + val(s[_i]);
    if(v > 9)
      lazy += v/10;
    u[i] = chr(j(v));   

    i++;
  }
}

void foo(string &s, int pot){
  s = "1";
  int i = 0;

  while(i < pot){
    add(s, s, 0);
    i++;
  }
}

string solve(){
  if(_n != n) return "0";

  int curn = 1;
  for(int i = 1; i <= llen; i++){
    if(l[i] == '0' || l[i] == '1') curn++;
    else{
      int v = vartoint(l[i]);
      int startn = curn;
      int end = curn + z[v];
      while(curn < end){
        make_union(curn, idx[v]+(curn-startn));
        curn++;
      }
    }
  }

  curn = 1;
  for(int i = 1; i <= rlen; i++){
    if(r[i] == '0' || r[i] == '1') curn++;
    else{
      int v = vartoint(r[i]);
      int startn = curn;
      int end = curn + z[v];
      while(curn < end){
        make_union(curn, idx[v]+(curn-startn));
        curn++;
      }
    }
  }

  int w = 0;
  vector<bool> team_on(n+1, false);
  for(int i = 1; i <= n; i++){
    if(is1[p[i]] && is0[p[i]])
      return "0";
    if(!team_on[p[i]] && !is1[p[i]] && !is0[p[i]])
      w++, team_on[p[i]] = true;
  } 
  
  string ans = "1";
  foo(ans, w);
  reverse(all(ans));
  return ans;
}

signed main(){
  fastio;
  int t;
  cin >> t;
  
  while(t--){
    cin >> k;
    z.assign(k+1, 0);
    idx.assign(k+1, 0);
    for(int i = 1; i <= k; i++) cin >> z[i];
    
    cin >> llen;
    l.assign(llen+1, 0);
    for(int i = 1; i <= llen; i++) cin >> l[i];

    cin >> rlen;
    r.assign(rlen+1, 0);
    for(int i = 1; i <= rlen; i++) cin >> r[i];

    _n = n = 1;
    is1.assign(10002, false);
    is0.assign(10002, false);

    for(int i = 1; i <= llen; i++){
      if(l[i] == '0')
        is0[n] = true, n++;
      else if(l[i] == '1')
        is1[n] = true, n++;
      else{
        idx[vartoint(l[i])] = n;
        n += z[vartoint(l[i])];
      }
    }

    for(int i = 1; i <= rlen; i++){
      if(r[i] == '0')
        is0[_n] = true, _n++;
      else if(r[i] == '1')
        is1[_n] = true, _n++;
      else{
        idx[vartoint(r[i])] = _n;
        _n += z[vartoint(r[i])];
      }
    }

    n--, _n--;

    p.assign(n+1, 0);
    for(int i = 1; i <= n; i++)
      make_set(i);

    cout << solve() << "\n";
  }
}