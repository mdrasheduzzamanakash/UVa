#include <bits/stdc++.h>
using namespace std;




int main() {
    long long int d[101][101], t[101][101];
    int T;
    cin >> T;
    while(T--){
        int v,e,s,ed;
        long long int tm,l;
        cin >> v >> e;
        memset(d,-1,sizeof d);
        memset(t,-1,sizeof t);
        for(int i = 1;i <= v;i++)
            d[i][i] = t[i][i] = 0;
        
        for(int i = 1;i <= e;i++){
            cin >> s >> ed >> tm >> l;
            if(d[s][ed] == -1 || t[s][ed] > tm || (t[s][ed] == tm && d[s][ed] > l)){
                d[s][ed] = d[ed][s] = l;
                t[s][ed] = t[ed][s] = tm;
            }
        }

        for(int k = 1;k <= v;k++){
            for(int i = 1;i <= v;i++){
                for(int j = 1;j <= v;j++){
                    if(t[i][k] != -1 && t[k][j] != -1){
                        if(t[i][j] == -1 || t[i][j] >= t[i][k] + t[k][j]){
                            if(t[i][j] == t[i][k] + t[k][j] && d[i][j] > d[i][k] + d[k][j])
                                continue;
                            t[i][j] = min(t[i][k] + t[k][j],t[i][j]);
                            d[i][j] = min(d[i][k] + d[k][j],d[i][j]);
                        }
                    }
                }
            }
        }

        int q;
        cin >> q;
        while(q--){
            int x,y;    cin >> x >> y;
            if(d[x][y] == -1)printf("No Path.\n");
            else printf("Distance and time to reach destination is %lld & %lld.\n", d[x][y], t[x][y]);
        }
        if(T)
        cout << endl;
    }
}