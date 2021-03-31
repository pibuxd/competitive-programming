#include "iostream"
#include "map"
#include "vector"
#include "queue"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

void createParents(const vector<vector<int>> &G, vector<int> &parent, const int lmiast){
  vector<bool> visited(lmiast+1);
  visited[1] = true;
  queue<int> Q;
  Q.push(1);

  while(!Q.empty()){
    int n = Q.front();
    Q.pop();

    for(int i = 0; i < G[n].size(); i++)
      if(!visited[G[n][i]]){
        visited[G[n][i]] = true;
        Q.push(G[n][i]);

        parent[G[n][i]] = n;
      }
  }
}

int sumDiff(int x, const vector<int> &parent, map<pair<int, int>, int> &IT, const int lrodzaj){
  int sum = 0;
  vector<bool> exists(lrodzaj+1);

  while(x != 1){
    if(!exists[IT[{x, parent[x]}]]){
      exists[IT[{x, parent[x]}]] = true;
      sum++;
    }

    x = parent[x];
  }

  return sum;
}

int main(){ fastio;
  int lmiast, lrodzaj, tests; cin >> lmiast >> lrodzaj >> tests;

  vector<pair<int, int>> Droga; // change resize
  Droga.push_back({0, 0});

  vector<vector<int>> G(lmiast+1);
  map<pair<int, int>, int> IT;

  for(int i = 1; i < lmiast; i++){
    int a, b, c; cin >> a >> b >> c;
    G[a].push_back(b);
    G[b].push_back(a);
    IT[{a, b}] = c;
    IT[{b, a}] = c;
    Droga.push_back({a, b});
  }

  vector<int> parent(lmiast+1);
  createParents(G, parent, lmiast);

  char zapytanie;
  int x, change;
  while(tests--){
    cin >> zapytanie >> x;

    if(zapytanie == 'Z'){ // x - docelowy wierzcholek
      cout << sumDiff(x, parent, IT, lrodzaj) << '\n';

    } else{ // x - numer drogi na ktorej wystepuje zmiana biciaka
      cin >> change;

      IT[{Droga[x].first, Droga[x].second}] = change;
      IT[{Droga[x].second, Droga[x].first}] = change;
    }
  }
}
