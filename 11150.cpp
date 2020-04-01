#include <bits/stdc++.h>
using namespace std;








int main() {
//    freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
   int n;
   while (scanf("%d",&n) == 1){
       int e = n,cnt = n;
       while(e != 1 && e != 2){
           int nb = e / 3;
           cnt += nb;
           e = e - (nb*3) + nb;
       }
       if(e == 2){
           cnt++;
       }
       cout << cnt << endl;
   }
   
}