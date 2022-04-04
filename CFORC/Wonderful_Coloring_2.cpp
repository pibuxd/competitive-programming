// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
  fastio;
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector<int> v(n+1), in(n);

    for(int i = 0; i < n; i++){
      cin >> in[i];
      v[in[i]]++;
    }

    int temp = 0, ans = 0;
    stack<array<int, 2>> to_add;
    vector<int> how(n+1);

    int it = 0;
    for(int x : v){
      if(x >= k){
        ans++;
        how[it] = k;
      } else{ // x < k
        if(temp + x > k)
          x = k-temp;
        temp += x;
        to_add.push({it, x});
        if(temp == k){
          temp = 0, ans++;
          while(!to_add.empty()){
            auto _t = to_add.top();
            to_add.pop();
            how[_t[0]] += _t[1];
          }
        }
      }

      it++;
    }


    // cout << ans << "\n";
    int z = 0;
    vector<int> wyk(n+1);
    for(int x : in){
      if(!how[x]){
        cout << "0 ";
        continue; 
      }

      if((wyk[x] + how[x]) == k){
        how[x]--, wyk[x]++;
        cout << wyk[x] << " ";
      } else{
        how[x]--, z++;
        cout << z << " ";
        if(z == k) z = 0;
      }
    }
    cout << "\n";
  }
}