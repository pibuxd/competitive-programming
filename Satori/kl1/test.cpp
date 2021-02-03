#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

class partia
{
  public:
    unsigned int number = 0;
		unsigned int mand = 0;
    unsigned int start = 0;
};


void boost()
{
  std::ios_base::sync_with_stdio(0);
}


bool operator<(partia A, partia B)
{
  unsigned int glosyA = A.start/(A.mand+1);
  unsigned int glosyB = B.start/(B.mand+1);

  if(glosyA>glosyB){return true;}
  if(glosyA<glosyB){return false;}
  if(glosyA==glosyB)
  {
    if(A.start!=B.start)
    {
      return (A.start>B.start?true:false);
    }
    else
    {
      return (A.number>B.number?true:false);
    }
  }
}


int main(int argc, char const *argv[])
{
  boost();
  unsigned int loop;
  std::cin>>loop;

  unsigned int n; //ilosc komitetow
  unsigned int k; //ilosc mandatow
  std::cin>>n>>k;

  std::vector<partia> vec;
  for(auto i=1;i<n+1;++i)
  {
    unsigned int temp;
    std::cin>>temp;
    vec[i].start = temp;
    vec[i].number = i;
  }


  return 0;
}
