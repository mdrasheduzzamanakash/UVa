#include <bits/stdc++.h>
using namespace std;
int g[21][21];
int p[21];
void reset(){
    for(int i = 0;i < 21;i++)
        for(int j = 0;j < 21;j++)
            g[i][j] = 0;
}
int main() {
    int n,kse = 0;
    while(scanf("%d",&n) == 1){
        reset();
        for(int i = 1;i <= 19;i++){
            if(i != 1){
                cin >> n;
            }
            while(n--){
                int x; cin >> x;
                g[i][x] = 1;
                g[x][i] = 1;
            }
        }
        for(int k = 1;k <= 20;k++){
            for(int i = 1;i <= 20;i++){
                for(int j = 1;j <= 20;j++){
                    if(g[i][j] == 0 || g[i][j] > g[i][k] + g[k][j]){
                        if(g[i][k] && g[k][j])
                            g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
        cin >> n;
        printf("Test Set #%d\n", ++kse);
        while(n--){
            int x,y;
            cin >> x >> y;
            printf("%2d to %2d: %d\n",x,y,g[x][y]);
        }
        puts("");
    }
    return 0;
}