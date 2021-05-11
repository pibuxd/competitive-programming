#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Graph{
  int n, trans;
  vector<int> lab;
  vector<vector<int>> G;

  Graph(int _n){
    n = _n;
    trans = 0;
    lab.resize(n+1);
    G.resize(n+1);
  }

  void set(int x, int i){
    lab[i] = x;
  }

  void push(int a, int b){
    G[a].push_back(b);
  }
  
  void run(){
    trans = 0;

    vector<int> opened_for(n+1);
    for(int i = 1; i <= n; i++) for(int x : G[i]) opened_for[x]++;

    stack<int> S1, S2;

    for(int i = 1; i <= n; i++){
      if(opened_for[i] == 0){
        if(lab[i] == 1)
          S1.push(i);
        else
          S2.push(i);
      }
    }

    int current = 1, v;
    if(S1.empty()) current = 2;

    while(!S1.empty() || !S2.empty()){
      //cout << "TRANSFORMS: " << trans << "\n";
      //cout << "CURRENT: " << current << "\n";
      
      if(current == 1 && S1.empty()){
        current = 2;
        trans++;
      } else if(current == 2 && S2.empty()){
        current = 1;
        trans++;
      }
  
      if(current == 1){
        v = S1.top();
        S1.pop();
      } else{
        v = S2.top();
        S2.pop();
      }

      for(int x : G[v]){
        opened_for[x]--;

        if(opened_for[x] == 0){
          if(lab[x] == 1){
            S1.push(x);
          } else{
            S2.push(x);
          }
        }
        //cout << "SIZES: " << S1.size() << "," << S2.size() << "\n";
      }
    }
    int trans2 = trans;

    trans = 0;

    opened_for = vector<int>(n+1);
    for(int i = 1; i <= n; i++) for(int x : G[i]) opened_for[x]++;

    S1 = S2 = stack<int>();

    for(int i = 1; i <= n; i++){
      if(opened_for[i] == 0){
        if(lab[i] == 1)
          S1.push(i);
        else
          S2.push(i);
      }
    }

    current = 2;
    if(S2.empty()) current = 1;

    while(!S1.empty() || !S2.empty()){
      //cout << "TRANSFORMS: " << trans << "\n";
      //cout << "CURRENT: " << current << "\n";
      
      if(current == 1 && S1.empty()){
        current = 2;
        trans++;
      } else if(current == 2 && S2.empty()){
        current = 1;
        trans++;
      }
  
      if(current == 1){
        v = S1.top();
        S1.pop();
      } else{
        v = S2.top();
        S2.pop();
      }

      for(int x : G[v]){
        opened_for[x]--;

        if(opened_for[x] == 0){
          if(lab[x] == 1){
            S1.push(x);
          } else{
            S2.push(x);
          }
        }
        //cout << "SIZES: " << S1.size() << "," << S2.size() << "\n";
      }
    }

    trans = min(trans, trans2);
  }

  int min_num_of_transfers(){
    return trans;
  }
};

int main(){
  fastio;
  int t; cin >> t;

  while(t--){
    int n, m; cin >> n >> m;

    Graph graph(n);

    for(int i = 1; i <= n; i++){
      int a; cin >> a;
      graph.set(a, i);
    }

    while(m--){
      int a, b; cin >> a >> b;
      graph.push(a, b);
    }

    graph.run();
    cout << graph.min_num_of_transfers() << "\n";
  }
}