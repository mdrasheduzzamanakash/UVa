#include <bits/stdc++.h>
using namespace std;
#define oo 0xfffffff



int main() {
    //           freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int p,r,bh,o,eh,m;
    while(scanf("%d%d%d%d%d%d",&p,&r,&bh,&o,&eh,&m) == 6){
        int x,y,d;
        int g[110][110],gb[110][110];
        for(int i = 0;i < 110;i++){
            for(int j = 0;j < 110;j++){
                g[i][j] = oo,gb[i][j] = oo;
            }g[i][i] = 0,gb[i][i] = 0;
        }

        for(int i = 0;i < r;i++){
            cin >> x >> y >> d;
            g[x][y] = g[y][x] = gb[x][y] = gb[y][x] = d;
        }

        //sp for boss
        for(int k = 1;k <= p;k++){
            for(int i = 1;i <= p;i++){
                for(int j = 1;j <= p;j++){
                    if(gb[i][j] == oo || gb[i][k]+gb[k][j] < gb[i][j]){
                        if(gb[i][k] != oo || gb[k][j] != oo){
                            gb[i][j] = gb[i][k]+gb[k][j]; 
                        }
                    }
                }
            }
        }

        bitset<110> baned;
        baned.reset();
        int sp = gb[bh][o];

        for(int i = 1;i <= p;i++){
            if(gb[bh][i] + gb[i][o] == sp){
                baned.set(i);
                // g[i][i] = oo;
            }
        }

        for(int k = 1;k <= p;k++){
            if(baned.test(k))continue;
            for(int i = 1;i <= p;i++){
                if(baned.test(i))continue;
                for(int j = 1;j <= p;j++){
                    if(baned.test(j))continue;
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
                }
            }
        }

        if(g[eh][m] == oo || baned.test(eh) || baned.test(m)){
            printf("MISSION IMPOSSIBLE.\n");
        }else printf("%d\n",g[eh][m]);
    }
    return 0;
}