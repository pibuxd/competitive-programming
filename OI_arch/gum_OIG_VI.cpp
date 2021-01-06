#include <bits/stdc++.h>
using namespace std;

bool malejaco(string &s1,string &s2){
    return s1.size() > s2.size();
}

int main(){
  int n; cin >> n;
  vector<string> V, SORTED;

  for(int i = 0; i < n; i++){
    string p; cin >> p;
    V.push_back(p);
    sort(p.rbegin(), p.rend());
    SORTED.push_back(p);
    sort(SORTED.begin(), SORTED.end(), malejaco);
  }

  string same;
  bool if = false;
  int i = 0, IT[n];
  fill(IT, IT+n, 0);

  while(i < SORTED[0].size()){
    char max = 'a';

    for(int it = 0; it < n; i++){
      if(SORTED[it][IT[it]] > max){
        max = SORTED[it][IT[it]];
      }
      else if(SORTED[it][IT[it]] == max){
        max = SORTED[it][IT[it]];
      }
    }

  }
}
