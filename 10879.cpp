#include <bits/stdc++.h>
using namespace std;








int main() {
   // freopen("i.txt","r",stdin);
   // freopen("o.txt","w",stdout);

   int T;
   cin >> T;
   for(int c = 1;c <= T;c++){
       int aa,bb,cc,dd,cnt = 0;
       set<int>s;
       int n;
       cin >> n;
       for(int i = 2;i <= sqrt(n);i++){
           if(n % i == 0){
               if(!cnt){
                   aa = i; bb = n / i; cnt++;
               }else{
                   cc = i; dd = n / i;
                   if(cc != aa || cc != bb || dd != aa || dd != bb) break;
               }
           }
       }

       printf("Case #%d: %d = %d * %d = %d * %d\n",c,n,aa,bb,cc,dd);
   }
}