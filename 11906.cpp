#include <bits/stdc++.h>
using namespace std;
#define mx 102
int r,c,m,n,w;
int pro[2] = {1,-1};
int g[mx][mx], visited[mx][mx], cnt[mx][mx];


void dfs(int x,int y){
    // terminating condition
    if(visited[x][y])   return;
    visited[x][y] = 1;

    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++){
            int nx = x+pro[i]*m, ny = y+pro[j]*n;
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != -1){
                cnt[nx][ny]++;
                dfs(nx,ny);
            }
            nx = x+pro[i]*n, ny = y+pro[j]*m;
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != -1){
                cnt[nx][ny]++;
                dfs(nx,ny);
            }
        }
    }
}


int main(){
    int t;
    cin >> t;
    for(int tc = 1;tc <= t;tc++){
        // clean
        memset(g,0,sizeof g);
        memset(visited,0,sizeof visited);
        memset(cnt,0,sizeof cnt);
        int even = 0;
        int odd = 0;
        cin >> r >> c >> m >> n >> w;
        for(int i = 0,x,y;i < w;i++){
            cin >> x >> y;
            g[x][y] = -1;
        } // ends of input

        dfs(0,0);

        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(m == 0 || n == 0 || m == n) cnt[i][j] /= 2;
                if(cnt[i][j] || (!i && !j)){
                    if(cnt[i][j] % 2 == 0) even++;
                    else odd++; 
                }
            }
        }
        printf("Case %d: %d %d\n",tc,even,odd);
    }
    return 0;
}