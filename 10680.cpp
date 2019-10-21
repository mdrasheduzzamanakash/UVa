#include<bits/stdc++.h>
#define mx 130
#define ll long long
using namespace std;


bitset<mx>bs;
vector<ll>p;
void Sieve(){
   bs.set();
   bs[0] = bs[1] = false;
   p.push_back(2);
   for(int i = 4;i < mx;i += 2)bs[i] = false;
   for(int i = 3; i*i < mx;i += 2){
      if(bs[i])
         for(int j = i*i; j < mx; j += 2*i)
            bs[j] = false;
   }

   for(int i = 3;i < mx;i++)
      if(bs[i] == true) p.push_back(i);

   swap(p[1],p[2]);
}



int main() {
   Sieve();
   ll n = 1;
   for(int i = 0;i <= 30;i++)cout << p[i] <<" ";
   while(scanf("%lld",&n) == 1 && n) {
      ll c2 = 0,c5 = 0,r = 1;
      for(ll i = 2;i <= n;i *= 2)c2++;
      for(ll i = 5;i <= n;i *= 5)c5++;

      for(ll i = 0;i < c2 - c5;i++)
         r = (r * 2) % 10;

      for(ll i = 2; p[i] <= n && i < p.size() ;i++){
         for(ll va = p[i]; va <= n; va *= p[i])
            r = (r * p[i]) % 10;
      }

      cout << r << "\n";
   }      
}
