#include <bits/stdc++.h>
using namespace std;

// not solved






int main() {
       freopen("i.txt","r",stdin);
   freopen("o.txt","w",stdout);
    int m,x;
    while(cin >> m >> x && (m || x)){
        int ans = -1;
        int cnt = 0;
        for(int v = m;;){
            int u = (v * (100 - x))/100;
            if(u < m-1){
                ans = v;
                if(cnt == 0) v = v*100;
                else         v++;
            }else  {
                if(cnt == 0)v = v / 100,cnt++;
                else break;
            }
        }
        if(ans == -1)printf("Not found\n");
        else         printf("%d\n",ans);
    }
    return 0;
}