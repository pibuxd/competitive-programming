// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include<bits/stdc++.h>
using namespace std;
int n;
int maxHist(int row[])
{
    stack<int> result;
    int top_val;
    int max_area = 0;
    int area = 0;
    int i = 0;

    while(i < n){
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else{
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1 );
            max_area = max(area, max_area);
        }
    }

    while(!result.empty()){
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;

        if (!result.empty())
            area = top_val * (i - result.top() - 1 );

        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(int A[n][n]){
    int result = maxHist(A[0], n);

    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++)
            if (A[i][j]) A[i][j] += A[i - 1][j];

        result = max(result, maxHist(A[i]));
    }
    return result;
}

int main(){
  int t; cin >> t;

  while(t--){
    cin >> n;
    int A[n][n];

    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cin >> A[i][j];
      }
    }

    cout << maxRectangle(A[n][n]) << '\n';
  }
}
