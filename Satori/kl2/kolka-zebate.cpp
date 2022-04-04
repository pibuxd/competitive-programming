// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct Fraction {
   int a, b;

   Fraction reduce(Fraction f){
      int d = __gcd(f.a, f.b);

      f.a = f.a / d;
      f.b = f.b / d;

      return f;
   }

   Fraction add(Fraction x, Fraction y){
      Fraction ans;
      ans.b = __gcd(x.b, y.b);
      ans.b = x.b * y.b / ans.b;

      ans.a = (x.a * ans.b / x.b) + (y.a * ans.b / y.b);

      return reduce(ans);
   }
};

struct Kolo {
   int x, y, r;
   Fraction v = {0, 0};
   int kier = -1; // kierunek obrotu kola zgodnie->0/przeciwnie->1/zatrzymane->-1 do wskazowek zegara
};

struct Uklad {
   int n;
   vector<Kolo> kola;

   Uklad(int _n){
      n = _n;
      kola.resize(n+1);
   }

   void push(Kolo k, int i){
      kola[i] = k;
   }

   void run(){
      kola[1].v = {1, 1};
      kola[1].kier = 0;
   }

   string kierunek(int kier){
      if(kier == -1)
         return "zatrzymane";
      else if(kier == 0)
         return "zgodnie";
      else // kier == 1
         return "przeciwnie";
   }

   void print(){
      for(int i = 1; i <= n; i++){
         Fraction ans = kola[i].v;
         if(ans.a%ans.b == 0)
            cout << ans.a/ans.b << " " << kierunek(kola[i].kier) << "\n";
         else
            cout << ans.a << "/" << ans.b << " " << kierunek(kola[i].kier) << "\n";
      }
   }
};

int main(){
   fastio;
   int t;
   cin >> t;

   while(t--){
      int n;
      cin >> n;

      Uklad uklad(n);

      for(int i = 1, x, y, r, v; i <= n; i++){
         cin >> x >> y >> r;

         Kolo k;
         k.x = x, k.y = y; k.r = r;
         uklad.push(k, i);
      }

      uklad.run();
      uklad.print();
   }

  
}