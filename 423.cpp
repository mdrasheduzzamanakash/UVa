#include <bits/stdc++.h>
using namespace std;
#define INF 0xfffffff


int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,g[200][200],x;
    while(cin >> n){
        for(int i = 0;i < n;i++){
            g[i][i] = 0;
        }

        for(int i = 1;i < n;i++){
            for(int j = 0;j < i;j++){
                if(scanf("%d",&x) == 1){
                    g[i][j] = g[j][i] = x;
                }else {
                    g[i][j] = g[j][i] = INF;
                    scanf("%*c");
                }
            }
        }

        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(g[i][j] > g[i][k]+g[k][j]){
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans , g[0][i]);
        }
        cout << ans << endl;
    }
    return 0;
}