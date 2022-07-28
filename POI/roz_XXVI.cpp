#include <bits/stdc++.h>
using namespace std;

int m, p;
vector<long long> bit;

void fen_add(int idx, long long val){
  for(; idx <= m; idx += idx & -idx)
    bit[idx] += val;
}

long long fen_sum(int idx){
  long long sum = 0;
  for(; idx > 0; idx -= idx & -idx)
    sum += bit[idx];
  return sum;
}

long long fen_sum(int l, int r){
  return fen_sum(r) - fen_sum(l - 1);
}

int pos(int i){
  if(i <= p) return p - i + 1;
  else return p + m - i + 1;
}

void pmove(){
  p = (p == m ? 1 : p + 1);
}

void inicjuj(int _m){
  m = _m;
  p = 0;
  bit.assign(m+1, 0);
}

void koryguj(int i, int k){
  fen_add(pos(i), k);
}

void dodaj(int k){
  pmove();
  fen_add(pos(1), -fen_sum(pos(1), pos(1)));
  fen_add(pos(1), k);
}

long long suma(int i){  
  if(pos(i) <= pos(1)) return fen_sum(pos(i), pos(1));
  else return fen_sum(1, pos(1)) + fen_sum(pos(i), m);
}
