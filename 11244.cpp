#include <bits/stdc++.h>
using namespace std;
char graph[120][120];
int r,c;
bool flag;

int px[] = {-1,1,0,0,1,-1,-1,1};
int py[] = {0,0,-1,1,1,-1,1,-1};

void dfs(int x,int y,int dot){
    if(x < 0 || y < 0 || x >= r || y >= c || graph[x][y] == '.') return;
    // base con
    if(dot == 1 && graph[x][y] == '*') flag = true;
    // another con
    graph[x][y] = '.';
    for(int i = 0;i < 8;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        dfs(nx,ny,1);
    }
}

int main(){
    while(cin >> r >> c && r && c){
        for(int i = 0;i < r;i++) cin >> graph[i];
        // inp fin

        int ans = 0;
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++){
                if(graph[i][j] == '*'){
                    flag = false;
                    dfs(i,j,0);
                    if(!flag) ans++;
                }
            }
        cout << ans << endl;
    }
}