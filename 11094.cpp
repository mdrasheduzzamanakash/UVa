#include <bits/stdc++.h>
using namespace std;
char graph[150][150];
bool visited[150][150];
int r,c;
char land;

int dfs(int x,int y){
    if(x < 0 || x >= r || y < 0 || y >= c || visited[x][y] || graph[x][y] != land)
        return 0;
    int ans = 0;
    visited[x][y] = true;
    graph[x][y] = land-'0'+1;
    ans++;
    // call
    ans += dfs(x,y+1);
    ans += dfs(x,y-1);
    ans += dfs(x+1,y);
    ans += dfs(x-1,y);
    if(y == 0){
        ans += dfs(x,c-1);
    }else if(y == c-1){
        ans += dfs(x,0);
    }
    return ans;
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    while(cin >> r >> c){
        memset(visited, false, sizeof visited);
        for(int i = 0;i < r;i++) cin >> graph[i];
        int x,y;
        cin >> x >> y;
        // inp fin
        land = graph[x][y];
        int cnt = 0;
        int mx = 0;
        cnt = dfs(x,y);
        //........
        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                if(graph[i][j] == land && !visited[i][j]){
                    cnt = dfs(i,j);
                    mx = max(mx,cnt);
                }
        cout << mx << endl;
    }
}