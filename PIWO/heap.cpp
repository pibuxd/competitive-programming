// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include "bits/stdc++.h"
using namespace std;

int parent(int i){
  return (i-1)/2;
}
int left(int i){
  return 2*i+1;
}
int right(int i){
  return 2*i+2;
}
int heap_max(vector<int> &H){
  return H[0];
}
void heapify(vector<int> &H){
  int i_max = i;
  if(H[left(i)] > H[i_max] && H[left(i)] > H[i_max])
    i_max = left(i);
  if(H[right(i)] > H[i_max] && H[right(i)] > H[i_max])
    i_max = right(i);
  if(i_max != i){
    swap(H[i], H[i_max]);
    heapify(H, i_max);
  }
}
void heap_insert (vector<int> &H, int x){
  H.push_back(x);
  int i = H.size()-1;
  while(i > 0 && H[i] > H[parent]){
    swap(H[i], H[parent(i)]);
    i = parent(i);
  }
}
int heap_extract_max(vector<int> &H){
  int x = heap_max(H);
  H[0] = H[H.size()-1];
  H.pop_back();
  heapify(H, 0);
  return x;
}
int main(){
  vector<int> H;
  for(int i = 0; i < n; i++){
    heap_insert(H, rand()%100);
  }
  while(H.size() > 0){
    cout << heap_extract_max(H) << " ";
  }
}
