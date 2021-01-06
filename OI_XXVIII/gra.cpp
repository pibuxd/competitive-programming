#include "bits/stdc++.h"
using namespace std;

#define uChar unsigned char
#define uInt unsigned int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

class inParameters{
public:
	uInt liczba, dlg, tests;
};

class maximumInt{
	public:
		uInt i = 1000000001;
};

class V{
	public:
		uChar w = 0;
		uInt x, y;
		V(uInt a, uInt b):x(a),y(b){}
		V(uInt a, uInt b, uChar c):x(a),y(b),w(c){}
		V(){}
};
class E{
	public:
		V start, end;
		E(V a, V b):start(a),end(b){}
		E(){}
};

inline bool operator < (const V &l, const V &r){
	if(l.y != r.y)
		return (l.y < r.y);
	else
		return (l.x > r.x);
}

inline bool operator == (const V &l, const V &r){
	return (l.y == r.y) && (l.x == r.x);
}

template<>
struct std::less<V>{
	bool operator()(const V &l, const V &r) const noexcept{
		if(l.y == r.y)
		 	return (l.x > r.x);
		else
			return (l.y < r.y);
}};

template<>
struct std::hash<V>{
	uInt operator()(const V& a) const noexcept {
		uInt hash1 = hash<uInt>{}(a.x);
		uInt hash2 = hash<uInt>{}(a.y);
		return hash1 ^ hash2;
}};

class Graf{
	public:
		unordered_map<V, maximumInt> W;
		map<V, set<V>> Edges;
		void EADD(V a, V b){
			Edges[a].insert(b);
		}
		void VADD(V a){
			Edges[a];
		}
		void valueSET(V a, int b){
			W[a].i = b;
		}
		void EADD(V a, V b, int w){
			b.w = w;
			Edges[a].insert(b);
}};


void printTests(Graf& G, const vector<uInt>& Vkoncowe, const uInt& Alltests){
	for(uInt i = 0; i < Alltests; i++)
		cout << G.W[V(0, Vkoncowe[i])].i << '\n';
}

int main(){ fastio;
	inParameters input;
	cin >> input.liczba >> input.dlg >> input.tests;
	Graf G;
	queue<V> Q;

	for(uInt i = 0; i < input.liczba; i++){
		uInt ileDziur; cin >> ileDziur;

		for(uInt it = 1; it <= ileDziur; it++){
			uInt gdzieDziura; cin >> gdzieDziura;

			if(i < input.liczba-1){
				V a(gdzieDziura, i); V b(gdzieDziura-2, i); V c(gdzieDziura-1, i+1);
				G.EADD(a, b, 1); G.EADD(a, c, 1); G.EADD(c, b);
				G.VADD(b);
			} else{
				V a(gdzieDziura, i); V b(gdzieDziura-2, i);
				G.EADD(a, b, 1); G.VADD(b);
			}
		}

		V aa(input.dlg-1, i);
		G.VADD(aa);
		G.valueSET(aa, 0);
		Q.push(aa);
	}

	vector<uInt> Vkoncowe(input.tests);

	for(uInt i = 0; i < input.tests; i++){
		uInt pozycja; cin >> pozycja;
		Vkoncowe[i] = pozycja-1;
		V a(0, pozycja-1);
		G.VADD(a);
	}

	for(map<V, set<V>>::iterator mapIterator = G.Edges.begin(); next(mapIterator, 1) != G.Edges.end(); mapIterator++){
		if(mapIterator->first.x != 0){
			G.EADD(mapIterator->first, next(mapIterator, 1)->first);
		}
	}

	while(!Q.empty()){ // BFS
		V f = Q.front();
		Q.pop();
		uInt* WL = &G.W[f].i;

		for(V x : G.Edges[f]){
			G.W[x];
			uInt* Wdozamiany = &G.W[x].i;
			if(*Wdozamiany > *WL + x.w){
				Q.push(x);
				*Wdozamiany = *WL + x.w;
			}
		}
	}

	printTests(G, Vkoncowe, input.tests);
	return 0;
}
