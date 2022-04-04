// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(); cin.tie(); cout.tie();

void mergeArrays(ll a[], int low, int mid, int high){
  int i = low, j = mid + 1, index = low, temp[1000001], k;
  while((i <= mid) && (j <= high)){
    if(a[i] < a[j]){
      temp[index] = a[i];
      i++;
    } else{
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  if(i > mid){
    while(j <= high){
      temp[index] = a[j];
      j++;
      index++;
    }
  } else{
    while(i <= mid){
      temp[index] = a[i];
      i++;
      index++;
    }
  }
  for(k = low; k < index; k++){
    a[k] = temp[k];
  }
}

void mergeSort(ll a[], int low, int high){
  if(low < high){
    int middle = (low + high) / 2;
    mergeSort(a, low, middle);
    mergeSort(a, middle + 1, high);
    mergeArrays(a, low, middle, high);
  }
}

int howUnique(ll a[], int n){
  int ans = 1;

  for(int i = 0; i < n-1; i++)
    if(a[i] < a[i+1])
      ans++;

  return ans;
}

int main(){ fastio
  int n; cin >> n;
  if(n == 0){
    cout << '0';
    return 0;
  }
  ll a[n];

  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  mergeSort(a, 0, n - 1);

  cout << howUnique(a, n);
}
