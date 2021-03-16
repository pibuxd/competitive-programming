#include <bits/stdc++.h>
using namespace std;

int main(){ ios_base::sync_with_stdio(0); cin.tie(0);
  	int t, w, n;
  	cin >> t >> w >> n;
 	int M[n], T[n], W[n], V1[n][t+1], V2[n][t+1], V3[n][t+1];
	for(int i = 0; i < n; i++){
		cin >> M[i] >> T[i] >> W[i];
	}
	for(int i = 0; i < n; i++){ //zerowanie
   	for(int j = 0; j <= t; j++){
      V1[i][j] = 0;
			V2[i][j] = 0;
			V2[i][j] = 0;
    }
  }
	for(int i = 1; i <= t; i++){//1 kolumna
		if(i >= M[i]){
			V1[0][i] = M[0];
			V2[0][i] = T[0];
			V3[0][i] = W[0];
		}
	}
	for(int w = 1; w < n; w++){
		for(int o = 1; o <= t; o++){
      if((o >= M[w]) && ((M[w]+V[w-1][o-M[w]])>V[w-1][o-1]))

      }
		}
	}
}
