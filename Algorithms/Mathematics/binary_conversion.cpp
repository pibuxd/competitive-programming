// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
// * ways to convert binary to decimal and vice versa
// https://codeforces.com/blog/entry/73490
#include <bits/stdc++.h>
using namespace std;

int decimal;
vector<bool> binary(32);
bitset<32> binary_set;

// without any builtin std functions
void dec_to_bin(int x){
  int i = 0;
  while(x){
    binary[i] = x % 2;
    x /= 2;
    i++;
  }
}

// using only std::bitset
void dec_to_bin_bitset(int x){
  binary_set = x;
}

// with bitwise operators
void dec_to_bin_operators(int x){
  for(int i = 0; i <= 31; i++){
    if(x & (1 << i))
      binary[i] = true;
  }
}

int bin_to_dec_bitset(){
  return stoi(binary_set.to_string(), 0, 2);
}

int main(){
  cin >> decimal;

  dec_to_bin_bitset(decimal);
  cout << binary_set << "\n"; // printing std::bitset in reversed order

  dec_to_bin_operators(decimal);
  for(int i = 31; i >= 0; i--)
    cout << binary[i];
  cout << "\n";

  binary.resize(32);
  dec_to_bin(decimal);
  for(int i = 31; i >= 0; i--)
    cout << binary[i];
  cout << "\n";

  cout << bin_to_dec_bitset() << "\n";
}
