// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;


void boooooster()
{
	ios_base::sync_with_stdio(0);
}

struct partia
{
	int mand = 0;
	int start = 0;
};


bool operator(partia A, partia B)
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
      return (A.numer>B.numer?true:false);
    }
  }
}

int main()
{
	//boooooster();
	int loop;
	cin >> loop;
	while(loop--)
		{
			int n;
			int m;
			cin >> n >> m;

			priority_queue<pair<int,int>> Q;
			vector<partia> V;

			for(int i = 0; i < n; i++)
				{
					int p;
					cin >> p;

					Q.push(make_pair(p, i));
					V.push_back(partia());
					V[i].start = p;
				}

			cout << '\n'; //do debugu!

			while(m--)
				{ //rozdawanie mandatow
					int s = Q.top().second, f = Q.top().first;
					Q.pop();
					int s2 = Q.top().second, f2 = Q.top().first;

					if(f == f2)
						{ //jesli maja tyle samo glosow
							if(V[s].mand >= V[s2].mand)
								{
									V[s].mand++;
									Q.push(make_pair((V[s].start / V[s].mand), s));

									cout << (V[s].start / V[s].mand) << ' '; //do debugu!
								} else
								{
									Q.pop();
									V[s2].mand++;
									Q.push(make_pair((V[s2].start / V[s2].mand), s2));
									Q.push(make_pair(f, s));

									cout << (V[s2].start / V[s2].mand) << ' '; //do debugu!
								}
						} else
						{
							Q.pop();
							V[s2].mand++;
							Q.push(make_pair((V[s2].start / V[s2].mand), s2));
							Q.push(make_pair(f, s));

							cout << (V[s2].start / V[s2].mand) << ' '; //do debugu!
						}
				}

			cout << '\n'; //do debugu!
			for(int i = 0; i < n; i++)
				{ //wypisanie
					cout << V[i].mand << '\n';
				}

		}
}
