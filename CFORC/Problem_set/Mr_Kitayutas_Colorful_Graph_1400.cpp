#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph {
   int n;
   vector<vector<int>> team;
   
   Graph(int _n){
      n = _n;
      team.resize(101, vector<int>(101));

      for(int i = 1; i <= 100; i++){
         for(int j = 1; j <= 100; j++){
            team[i][j] = j;
         }
      }
   }

   int find_team(int a, int c){
      if(a == team[c][a])
         return a;
      return team[c][a] = find_team(team[c][a], c);
   }

   void push(int a, int b, int c){
      a = find_team(a, c);
      b = find_team(b, c);

      if(a != b)
         team[c][b] = team[c][a];

      int temp = find_team(a, c);
      

   }

   bool is_connected(int a, int b, int c){
      return team[c][a] == team[c][b];
   }

};

int main(){
   fastio;
   int n, m;
   cin >> n >> m;

   Graph graph(n);
   
   while(m--){
      int a, b, c;
      cin >> a >> b >> c;
      graph.push(a, b, c);
   }

   int q;
   cin >> q;
   while(q--){
      int a, b;
      cin >> a >> b;
      int ans = 0;

      for(int i = 1; i <= 100; i++){
         if(graph.is_connected(a, b, i))
            ans++;   
      }

      cout << ans << "\n";
   }
}