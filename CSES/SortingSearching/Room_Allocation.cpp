// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int n, k;
set<int> S;
vector<array<int, 3>> in; // start, end, nr
map<int, queue<int>> used_rooms;
queue<int> avail_rooms;
vector<int> where;

void free_rooms(set<int>::iterator it){
  while(it != S.begin()){
    while(!used_rooms[*it].empty()){
      avail_rooms.push(used_rooms[*it].front());
      used_rooms[*it].pop();
    }
    auto _it = it;
    it--;
    S.erase(_it);
  }
}

int main(){
  fastio;
  cin >> n;
  in.resize(n);
  where.resize(n);
  k = 0;

  for(int i = 0; i < n; i++){
    cin >> in[i][0] >> in[i][1];
    in[i][2] = i;
  }
  sort(in.begin(), in.end());
  S.insert(-1);

  for(auto &i : in){
    auto it = S.upper_bound(i[0]);
    it--;
    if(*it == i[0]){
      it--;
      free_rooms(it);
      it++;
    }
    else free_rooms(it);


    if(*it <= i[0]){
      if(!avail_rooms.empty()){
        int temp = avail_rooms.front();
        avail_rooms.pop();
        used_rooms[i[1]].push(temp);
        where[i[2]] = temp;
      }
      else{
        k++;
        used_rooms[i[1]].push(k);
        where[i[2]] = k;
      }
    }
    else{
      int r = avail_rooms.front();
      avail_rooms.pop();
      used_rooms[i[1]].push(r);
      where[i[2]] = r;
    }

    S.insert(i[1]);
  }

  cout << k << "\n";
  for(int i : where)
    cout << i << " ";
}