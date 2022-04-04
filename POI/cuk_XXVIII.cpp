// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<unsigned int> D(n), P(n), R(n);
  unsigned long long sumD = 0, sumP = 0, sumR = 0, sumAll = 0;
  unsigned int d1 = 1000000002, d2 = 1000000002, d3 = 1000000002, p1 = 1000000002, p2 = 1000000002, p3 = 1000000002, r1 = 1000000002, r2 = 1000000002, r3 = 1000000002;
  int d1it = 0, d2it = 0, d3it = 0, p1it = 0, p2it = 0, p3it = 0, r1it = 0, r2it = 0, r3it = 0;

  for(int i = 0; i < n; i++){
    cin >> D[i] >> P[i] >> R[i];
    sumD += D[i]; sumP += P[i]; sumR += R[i];
    sumAll += D[i] + P[i] + R[i];

    unsigned int maximum = max(max(D[i], P[i]), R[i]);
    sumAll -= maximum;

    if(maximum - D[i] < d1){
      d3 = d2; d3it = d2it;
      d2 = d1; d2it = d1it;
      d1 = maximum - D[i]; d1it = i;
    } else if(maximum - D[i] < d2){
      d3 = d2; d3it = d2it;
      d2 = maximum - D[i]; d2it = i;
    } else if(maximum - D[i] < d3){
      d3 = maximum - D[i]; d3it = i;
    }

    if(maximum - P[i] < p1){
      p3 = p2; p3it = p2it;
      p2 = p1; p2it = p1it;
      p1 = maximum - P[i]; p1it = i;
    } else if(maximum - P[i] < p2){
      p3 = p2; p3it = p2it;
      p2 = maximum - P[i]; p2it = i;
    } else if(maximum - P[i] < p3){
      p3 = maximum - P[i]; p3it = i;
    }

    if(maximum - R[i] < r1){
      r3 = r2; r3it = r2it;
      r2 = r1; r2it = r1it;
      r1 = maximum - R[i]; r1it = i;
    } else if(maximum - R[i] < r2){
      r3 = r2; r3it = r2it;
      r2 = maximum - R[i]; r2it = i;
    } else if(maximum - R[i] < r3){
      r3 = maximum - R[i]; r3it = i;
    }
  }

  int itd = 0, itp = 0, itr = 0;
  unsigned int minSum = 3000000001;

  if(minSum > d1+p1+r1 && d1it != p1it && d1it != r1it && p1it != r1it){
    minSum = d1+p1+r1;
    itd = d1it; itp = p1it; itr = r1it;
  }

  if(minSum > d1+p1+r2 && d1it != p1it && d1it != r2it && p1it != r2it){
    minSum = d1+p1+r2;
    itd = d1it; itp = p1it; itr = r2it;
  }

  if(minSum > d1+p1+r3 && d1it != p1it && d1it != r3it && p1it != r3it){
    minSum = d1+p1+r3;
    itd = d1it; itp = p1it; itr = r3it;
  }

  if(minSum > d1+p2+r1 && d1it != p2it && d1it != r1it && p2it != r1it){
    minSum = d1+p2+r1;
    itd = d1it; itp = p2it; itr = r1it;
  }

  if(minSum > d1+p2+r2 && d1it != p2it && d1it != r2it && p2it != r2it){
    minSum = d1+p2+r2;
    itd = d1it; itp = p2it; itr = r2it;
  }

  if(minSum > d1+p2+r3 && d1it != p2it && d1it != r3it && p2it != r3it){
    minSum = d1+p2+r3;
    itd = d1it; itp = p2it; itr = r3it;
  }

  if(minSum > d1+p3+r1 && d1it != p3it && d1it != r1it && p3it != r1it){
    minSum = d1+p3+r1;
    itd = d1it; itp = p3it; itr = r1it;
  }

  if(minSum > d1+p3+r2 && d1it != p3it && d1it != r2it && p3it != r2it){
    minSum = d1+p3+r2;
    itd = d1it; itp = p3it; itr = r2it;
  }

  if(minSum > d1+p3+r3 && d1it != p3it && d1it != r3it && p3it != r3it){
    minSum = d1+p3+r3;
    itd = d1it; itp = p3it; itr = r3it;
  }


  if(minSum > d2+p1+r1 && d2it != p1it && d2it != r1it && p1it != r1it){
    minSum = d2+p1+r1;
    itd = d2it; itp = p1it; itr = r1it;
  }

  if(minSum > d2+p1+r2 && d2it != p1it && d2it != r2it && p1it != r2it){
    minSum = d2+p1+r2;
    itd = d2it; itp = p1it; itr = r2it;
  }

  if(minSum > d2+p1+r3 && d2it != p1it && d2it != r3it && p1it != r3it){
    minSum = d2+p1+r3;
    itd = d2it; itp = p1it; itr = r3it;
  }

  if(minSum > d2+p2+r1 && d2it != p2it && d2it != r1it && p2it != r1it){
    minSum = d2+p2+r1;
    itd = d2it; itp = p2it; itr = r1it;
  }

  if(minSum > d2+p2+r2 && d2it != p2it && d2it != r2it && p2it != r2it){
    minSum = d2+p2+r2;
    itd = d2it; itp = p2it; itr = r2it;
  }

  if(minSum > d2+p2+r3 && d2it != p2it && d2it != r3it && p2it != r3it){
    minSum = d2+p2+r3;
    itd = d2it; itp = p2it; itr = r3it;
  }

  if(minSum > d2+p3+r1 && d2it != p3it && d2it != r1it && p3it != r1it){
    minSum = d2+p3+r1;
    itd = d2it; itp = p3it; itr = r1it;
  }

  if(minSum > d2+p3+r2 && d2it != p3it && d2it != r2it && p3it != r2it){
    minSum = d2+p3+r2;
    itd = d2it; itp = p3it; itr = r2it;
  }

  if(minSum > d2+p3+r3 && d2it != p3it && d2it != r3it && p3it != r3it){
    minSum = d2+p3+r3;
    itd = d2it; itp = p3it; itr = r3it;
  }


  if(minSum > d3+p1+r1 && d3it != p1it && d3it != r1it && p1it != r1it){
    minSum = d3+p1+r1;
    itd = d3it; itp = p1it; itr = r1it;
  }

  if(minSum > d3+p1+r2 && d3it != p1it && d3it != r2it && p1it != r2it){
    minSum = d3+p1+r2;
    itd = d3it; itp = p1it; itr = r2it;
  }

  if(minSum > d3+p1+r3 && d3it != p1it && d3it != r3it && p1it != r3it){
    minSum = d3+p1+r3;
    itd = d3it; itp = p1it; itr = r3it;
  }

  if(minSum > d3+p2+r1 && d3it != p2it && d3it != r1it && p2it != r1it){
    minSum = d3+p2+r1;
    itd = d3it; itp = p2it; itr = r1it;
  }

  if(minSum > d3+p2+r2 && d3it != p2it && d3it != r2it && p2it != r2it){
    minSum = d3+p2+r2;
    itd = d3it; itp = p2it; itr = r2it;
  }

  if(minSum > d3+p2+r3 && d3it != p2it && d3it != r3it && p2it != r3it){
    minSum = d3+p2+r3;
    itd = d3it; itp = p2it; itr = r3it;
  }

  if(minSum > d3+p3+r1 && d3it != p3it && d3it != r1it && p3it != r1it){
    minSum = d3+p3+r1;
    itd = d3it; itp = p3it; itr = r1it;
  }

  if(minSum > d3+p3+r2 && d3it != p3it && d3it != r2it && p3it != r2it){
    minSum = d3+p3+r2;
    itd = d3it; itp = p3it; itr = r2it;
  }

  if(minSum > d3+p3+r3 && d3it != p3it && d3it != r3it && p3it != r3it){
    minSum = d3+p3+r3;
    itd = d3it; itp = p3it; itr = r3it;
  }

  sumAll -= D[itd] + P[itp] + R[itr];

  if(sumD != 0){
    sumAll += max(max(D[itd], P[itd]), R[itd]);
  }
  if(sumP != 0){
    sumAll += max(max(D[itp], P[itp]), R[itp]);
  }
  if(sumR != 0){
    sumAll += max(max(D[itr], P[itr]), R[itr]);
  }

  cout << sumAll;
}
