#include <bits/stdc++.h>
using namespace std;
int d[105][105];
int r,c,sx,sy;
char g[105][105];





int hx[] = { -1, 1, 2, 2,  1, -1, -2, -2 };
int hy[] = {  2, 2, 1,-1, -2, -2, -1,  1 };  

int kx[] = { 0, 1,  0, -1, -1, 1,  1, -1 };
int ky[] = { 1, 0, -1,  0,  1, 1, -1, -1 };


int bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;

    while(!q.empty()){
        pair<int,int> p = q.front();
        
        if(g[p.first][p.second] == 'B'){
            return d[p.first][p.second];
        }
        q.pop();

        for(int i = 0;i < 8;i++){
            int nx = p.first + kx[i];
            int ny = p.second + ky[i];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] != 'Z' && d[nx][ny] == -1){
                d[nx][ny] = d[p.first][p.second] + 1;
                q.push(make_pair(nx,ny));
            }
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] == 'B'){
                return d[p.first][p.second]+1;
            }
        }
    }

    return -1;
    
}


int main() {
    int T;
    cin >> T;
    while(T--){
        cin >> r >> c;
        memset(d,-1,sizeof d);
        for(int i = 0;i < r;i++)
            scanf("%s",g[i]);
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                if(g[i][j] == 'Z'){
                    for(int k = 0;k < 8;k++){
                        int x = i + hx[k];
                        int y = j + hy[k];
                        if(x >= 0 && x < r && y >= 0 && y < c){
                            d[x][y] = INT_MAX;
                        }
                    }
                }
                if(g[i][j] == 'A'){
                    sx = i; sy = j;
                }
            }
        }
        int ans = bfs(sx,sy);
        if(ans == -1) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n",ans);
    }
}