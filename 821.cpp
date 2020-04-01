#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int a,b,kse = 0;
    while(cin >> a >> b){
        int g[101][101] = {0};
        bool p[101] = {false};

        if(a == 0 && b == 0) break;
        g[a][b] = 1;
        p[a] = true;
        p[b] = true;
        while(cin >> a >> b){
            if(a == 0 && b == 0) break;
            g[a][b] = 1;
            p[a] = true;
            p[b] = true;
        }
        //
        for(int k = 0 ;k < 101;k++){
            if(!p[k])continue;
            for(int i = 0;i < 101;i++){
                if(!p[i])continue;
                for(int j = 0;j < 101;j++){
                    if(!p[j] || i == j)continue;
                    // all working nodes are present
                    if(g[i][j] > g[i][k] + g[k][j] || g[i][j] == 0){
                        if(g[i][k] && g[k][j]){
                            g[i][j] = g[i][k] + g[k][j];
                        }
                    }
                }
            }
        }

        double ans = 0;
        for(int i = 0;i < 101;i++){
            for(int j = 0;j < 101;j++)
                if(g[i][j]){
                    ans += g[i][j];
                }
        }
        int cnt=  0;
        for(int i = 0;i < 101;i++)
            if(p[i])cnt++;
        int dcnt = cnt;
        cnt--;
        dcnt = dcnt * cnt;
        ans = ans / dcnt;
        // cout << dcnt << endl;
        printf("Case %d: average length between pages = %.3lf clicks\n",++kse,ans);
        
    }
}