#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(), x.end()

int n, m;
vector<vector<char>> t;
vector<vector<bool>> vis;

void dzielniki_do_tablicy(int num, vector<int> &arr){
  int square_root = (int)sqrt(num) + 1;

  for(int i = 1; i <= square_root; i++){ 
    if(num % i == 0 && i * i != num){
      arr.push_back(i);
      arr.push_back(num/i);
    }
    else if(num % i == 0 && i * i == num)
      arr.push_back(i);
  }
}

void print_ans(vector<int> &arr){
  sort(all(arr));
  int ans = 0;
  for(int i = 0; i <= (int)arr.size()-1; i++){
    if(i == (int)arr.size()-1)
      ans++;
    else if(arr[i] != arr[i+1])
      ans++;
  }
  cout << ans << "\n";
  for(int i = 0; i <= (int)arr.size()-1; i++){
    if(i == (int)arr.size()-1)
      cout << arr[i];
    else if(arr[i] != arr[i+1])
      cout << arr[i] << " ";
  }
}

void ans_dla_1(){
  vector<int> dziel;
  dzielniki_do_tablicy(n, dziel);
  dzielniki_do_tablicy(m, dziel);
  print_ans(dziel);
}

bool visit_down(const string &s, int dlg, int y, int x){
  int starty = y;
  int endy = starty + dlg-1;

  if(endy > n)
    return false;

  while(y <= endy){
    if(t[y][x] != s[y-starty] || vis[y][x]){
      y = starty;
      return false;
    }
    y++;
  }

  for(int i = starty; i <= endy; i++)
    vis[i][x] = true;

  y = endy;
  return true;
}

bool visit_right(const string &s, int dlg, int y, int x){
  int startx = x;
  int endx = startx + dlg-1;
  
  if(endx > m)
    return false;

  while(x <= endx){
    if(t[y][x] != s[x-startx] || vis[y][x]){
      x = startx;
      return false;
    }
    x++;
  }

  for(int i = startx; i <= endx; i++)
    vis[y][i] = true;

  x = endx;
  return true;
}

void skip_down(int &y, int &x){
  while(y <= n && vis[y][x])
    y++;
}

void go_right(int &y, int &x){
  y = 1, x++;
  skip_down(y, x);
}

bool check(const string &s, int dlg, int y, int x){
  // cout << "y = " << y << ", x = " << x << "\n";
  skip_down(y, x);

  if(y-1 == n && x == m)
    return true;
  else if(y-1 == n && x < m){
    go_right(y, x);
    return check(s, dlg, y, x);
  }

  if(visit_down(s, dlg, y, x))
    return check(s, dlg, y + dlg-1 + 1, x);  
  else if(visit_right(s, dlg, y, x))
    return check(s, dlg, y+1, x);
  
  return false;
}

bool _check(const string &s, int dlg){
  vis.assign(n+1, vector<bool>(m+1, false));
  return check(s, dlg, 1, 1);
}

int main(){
  // fastio;
  cin >> n >> m;
  t.resize(n+1, vector<char>(m+1));

  vector<bool> __is_litera(26, false);
  int __ile_liter = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
      cin >> t[i][j];
      if(!__is_litera[t[i][j] - 'a']) 
        __ile_liter++, __is_litera[t[i][j] - 'a'] = true;
    }
  
  char litera_pierwsza = t[1][1];
  // char litera_koncowa = t[n][m];
  
  if(__ile_liter == 1){
    ans_dla_1();
    return 0;
  }

  vector<bool> is_literax(26, false), is_literay(26, false);
  int ile_literx = 0, ile_litery = 0;
  string sampley = "", samplex = "";

  vector<int> ans;

  // tylko piony, tylko poziomy
  for(int i = 1; i <= n; i++){
    if(i+1 <= m && t[1][i+1] != litera_pierwsza)
      break;

    sampley += t[i][1];
    if(!is_literay[t[i][1] - 'a']) 
      ile_litery++, is_literay[t[i][1] - 'a'] = true;

    if(n % i == 0 && ile_litery == __ile_liter && _check(sampley, i))
      ans.push_back(i);
  }
  for(int i = 1; i <= m; i++){
    if(i+1 <= n && t[i+1][1] != litera_pierwsza)
      break;

    samplex += t[1][i];
    if(!is_literax[t[1][i] - 'a']) 
      ile_literx++, is_literax[t[1][i] - 'a'] = true;

    if(m % i == 0 && ile_literx == __ile_liter && _check(samplex, i))
      ans.push_back(i);
  }

  samplex = sampley = "";
  ile_literx = ile_litery = 0;
  is_literax.assign(26, false);
  is_literay.assign(26, false);

  for(int i = 1; i <= n; i++){
    if(!(i+1 <= m && t[1][i+1] == t[i][1]))
      break;

    sampley += t[i][1];
    if(!is_literay[t[i][1] - 'a']) 
      ile_litery++, is_literay[t[i][1] - 'a'] = true;

    if((n % i == 0 || m % i == 0) && _check(sampley, i))
      ans.push_back(i);
  }
  for(int i = 1; i <= m; i++){
    if(!(i+1 <= n && t[i+1][1] == t[1][i]))
      break;

    samplex += t[1][i];
    if(!is_literax[t[1][i] - 'a']) 
      ile_literx++, is_literax[t[1][i] - 'a'] = true;

    if((n % i == 0 || m % i == 0) && _check(samplex, i))
      ans.push_back(i);
  }
    
  print_ans(ans);
  // for(int a : ans) cout << a << "\n";
  // cout << _check("ca", 2) << "\n";
}