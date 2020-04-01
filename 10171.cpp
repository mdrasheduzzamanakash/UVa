#include <bits/stdc++.h>
using namespace std;
#define oo 0xfffffff

int main() {
    //      freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n;
    while(cin >> n && n){
        int g[26][26],gg[26][26];
        int val,x,y;
        for(int i = 0;i < 26;i++){
            for(int j = 0;j < 26;j++){
                g[i][j] = gg[i][j] = oo;
            }
            g[i][i] = gg[i][i] = 0;
        }

        char a,b,c,d;
        for(int i =0 ;i < n;i++){
            cin >> a >> b >> c >> d;
            cin >> val;
            x = c - 'A';
            y = d - 'A';

            if(a == 'Y'){
                if(b == 'U') g[x][y] = min(g[x][y],val);
                else g[x][y] = g[y][x] = min(g[y][x],val);
            }else{
                if(b == 'U') gg[x][y] = min(gg[x][y],val);
                else gg[x][y] = gg[y][x] = min(gg[y][x], val);
            }
        }

        cin >> a >> b;
        x = a - 'A';
        y = b - 'A';

        for(int k = 0;k < 26;k++){
            for(int i = 0;i < 26;i++){
                for(int j = 0;j < 26;j++){
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                    gg[i][j] = min(gg[i][j], gg[i][k]+gg[k][j]);
                }
            }
        }

        int ans = oo;
        for(int i = 0;i < 26;i++){
            if(g[x][i] + gg[y][i] < ans)
                ans = g[x][i] + gg[y][i];
        }
        if(ans == oo){
            printf("You will never meet.\n");
        }else {
            printf("%d",ans);
            for(int i = 0;i < 26;i++){
                if(g[x][i] + gg[y][i] == ans){
                    printf(" %c",i+'A');
                }
            }
            cout << endl;
        }
    }
    return(0);
}