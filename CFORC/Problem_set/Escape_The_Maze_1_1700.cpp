#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
vector<int> move_nr, start_room, vlad_move_nr;
vector<vector<int>> G;

int main(){
  fastio;
  int t;
  cin >> t;

  while(t--){
    cin >> n >> k;
    move_nr.assign(n+1, 0);
    vlad_move_nr.assign(n+1, 0);
    start_room.assign(n+1, 0);
    G.assign(n+1, vector<int>());
    vector<int> leaves;

    string ans = "NO";
    queue<pair<int, int>> q; // friend nr, move nr

    for(int i = 1; i <= k; i++){
      cin >> start_room[i];
      move_nr[start_room[i]] = -1;
      q.push({start_room[i], 0});
    }
    for(int i = 1; i <= n-1; i++){
      int a, b;
      cin >> a >> b;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    while(!q.empty()){
      auto node = q.front();
      q.pop();
      int v = node.first, curr = node.second+1;

      for(int x : G[v]){
        if(move_nr[x] == 0 || move_nr[x] > curr){
          move_nr[x] = curr;
          q.push({x, curr});
        }
      }
    }

    q.push({1, 0});

    while(!q.empty()){
      auto node = q.front();
      q.pop();
      int v = node.first, curr = node.second+1;

      for(int x : G[v]){
        if(x != 1 && (vlad_move_nr[x] == 0 || vlad_move_nr[x] > curr)){
          vlad_move_nr[x] = curr;
          q.push({x, curr});
        }
      }
    }

    for(int i = 2; i <= n; i++){
      int nodes = G[i].size();
      if(nodes == 1)
        leaves.push_back(i);
    }

    for(int l : leaves){
      if(vlad_move_nr[l] < move_nr[l])
        ans = "YES";
    }

    cout << ans << "\n";

    // cout << "\n";
    // for(int i = 1; i <= n; i++)
    //   cout << i << ": " << move_nr[i] << "\n";

    // cout << "\n";
    // for(int i = 1; i <= n; i++)
    //   cout << i << ": " << vlad_move_nr[i] << "\n";

    // cout << "\nleaves: ";
    // for(int i : leaves) 
    //   cout << i << " ";
  }

}