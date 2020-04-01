#include <bits/stdc++.h>
using namespace std;








int main() {
   // freopen("i.txt","r",stdin);
   // freopen("o.txt","w",stdout);
   int T;
   cin >> T;
   for(int kse = 1;kse <= T;kse++){
       int a,b;
       cin >> a >> b;
       int s = 0;
       for(int i = a;i <= b;i++){
           if(i % 2 != 0)
            s += i;
       }
       printf("Case %d: %d\n",kse,s);
   }
}