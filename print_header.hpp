/**
  * @brief Python like print
  * @author Cloud11665 (https://github.com/Cloud11665)
  */

#include <bits/stdc++.h>
using namespace std;

template<class T,class Y>ostream& operator<<(ostream&x,const pair<T,Y>&p)
{x<<"{"<<p.first<< "; "<<p.second<<"}";return x;}
template<class T>ostream&__print(ostream&x,string y,string z,string w,T j)
{x<<y;typename T::size_type i=0;for(auto it=j.begin();it!=j.end();++it,i++)
{x<<*it<<(i<j.size()-1?w:"");} x<<z;return x;}
#define _p1(n,b,c,d)template<class T>\
ostream&operator<<(ostream&x,const n<T>&j){return __print(x,b,c,d,j);}
#define _p2(n,b,c,d)template<class T,class Y>\
ostream&operator<<(ostream&x,const n<T,Y>&j){return __print(x,b,c,d,j);}
_p1(vector,"[","]",", ") _p1(set,"{","}",", ") _p1(unordered_set,"{", "}",", ")
_p2(map,"{","}",", ") _p2(unordered_map,"{", "}",", ")