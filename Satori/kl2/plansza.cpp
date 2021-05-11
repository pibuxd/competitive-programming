/**
 * * FIND AND UNION
 * * Na poczatku wszystkie pola sa zjedzone,
 * * a potem ide input od tylu i odjadam pole.
 * * Dzieki temu latwiej jest zrobic find and union.
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Plansza {
  int n, teams;
  vector<vector<bool>> tab; // 0 -> zjedzone, 1 -> niezjedzone
  vector<vector<pair<int, int>>> team;

  Plansza(int _n){
    n = _n;
    teams = 0;
    tab.resize(n+1, vector<bool>(n+1));
    team.resize(n+1, vector<pair<int, int>>(n+1));

    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++)
        team[i][j] = {i, j};
    }
  }

  pair<int, int> find_team(pair<int, int> p){
    if(team[p.first][p.second] == p)
      return p;
    
    return team[p.first][p.second] = find_team(team[p.first][p.second]);
  }

  void make_team(pair<int, int> a, pair<int, int> b){
    //cout << "PARA: " << a.first << "," << a.second << "\n";
    pair<int, int> x = find_team(a);
    pair<int, int> y = find_team(b);

    if(x != y){
      team[y.first][y.second] = x;
      teams--;
    }
  }

  void push(int x, int y){
    tab[x][y] = true;
    bool is_new = true;

    if(tab[x][y-1]){
      make_team({x, y}, {x, y-1});
    }
    if(y != n && tab[x][y+1]){
      make_team({x, y}, {x, y+1});
    }
    if(tab[x-1][y]){
      make_team({x, y}, {x-1, y});
    }
    if(x != n && tab[x+1][y]){
      make_team({x, y}, {x+1, y});
    }

    teams++;
  }

  int number_of_teams(){
    return teams;
  }
};

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int pole = n*n;

    Plansza plansza(n);

    vector<pair<int, int>> input(pole);
    for(int i = 0; i < pole; i++){
      int temp1, temp2;
      cin >> temp1 >> temp2;
      input[i] = {temp1, temp2};
    }

    vector<int> output(pole);
    for(int i = pole-1; i > 0; i--){
      plansza.push(input[i].first, input[i].second);
      output[i] = plansza.number_of_teams();
    }

    for(int i = 1; i < pole; i++){
      cout << output[i] << " ";
    }

    cout << "0 \n";
  }
}
