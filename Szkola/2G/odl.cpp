#include "bits/stdc++.h"
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){ fastio;
  int n; cin >> n;
  float a[n][3];

  for(int it = 0; it < n; it++)
    cin >> a[it][0] >> a[it][1] >> a[it][2];

  float minimum = 1000000001.00;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i != j){
        float odl = sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) +
                          (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]));
        if(odl < minimum)
          minimum = odl;
      }
    }
  }

  float maximum = 0.00;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i != j){
        float odl = sqrt((a[i][0] - a[j][0]) * (a[i][0] - a[j][0]) +
                          (a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]));
        if(odl > minimum)
          maximum = odl;
      }
    }
  }

  cout << setprecision(2) << fixed << minimum << ' ' << maximum;
}
