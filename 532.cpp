#include <bits/stdc++.h>
using namespace std;
int L,R,C;
int sr,sc,sl, dr,dc,dl;
int g[30][30][30];
bool visit[30][30][30];
int dis[30][30][30];

struct node{
    int l,r,c;
};

int pr[] = {0,0,1,-1,0,0};
int pc[] = {1,-1,0,0,0,0};
int pl[] = {0,0,0,0,1,-1};

bool isValid(int r,int c,int l){
    if(r < 0 || r >= R || c < 0 || c >= C || l < 0 || l >= L)
        return false;
    if(g[r][c][l] == -1)
        return false;
    return true;
}

void bfs(){
    queue<node> q;
    node src;
    src.l = sl;
    src.r = sr;
    src.c = sc;
    visit[sr][sc][sl] = true;
    q.push(src);
    dis[src.r][src.c][src.l] = 0;
    while(!q.empty()){
        node cur,top = q.front();
        q.pop();
        for(int i = 0;i < 6;i++){
            int nr = top.r + pr[i];
            int nc = top.c + pc[i];
            int nl = top.l + pl[i];

            if(isValid(nr,nc,nl) && !visit[nr][nc][nl]){
                visit[nr][nc][nl] = true;
                cur.r = nr;
                cur.c = nc;
                cur.l = nl;
                q.push(cur);
                dis[nr][nc][nl] = dis[top.r][top.c][top.l] + 1;
            }
        }
    }  
}

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    while(cin >> L >> R >> C && (L || R || C)){
        for(int i = 0; i < 30;i++)
            for(int j = 0;j < 30;j++)
                for(int k = 0;k < 30;k++)
                    visit[i][j][k] = false,dis[i][j][k] = 0;

        for(int l = 0;l < L;l++){
            for(int r = 0;r < R;r++){
                for(int c = 0;c < C;c++){
                    char ch;
                    cin >> ch;
                    if(ch == '#') g[r][c][l] = -1;
                    if(ch == '.') g[r][c][l] = 0;
                    if(ch == 'S') g[r][c][l] = 0,sr = r,sc = c,sl = l;
                    if(ch == 'E') g[r][c][l] = 0,dr = r,dc = c,dl = l;
                }
            }
        }
        bfs();
        if(visit[dr][dc][dl] == true)
            printf("Escaped in %d minute(s).\n",dis[dr][dc][dl]);
        else printf("Trapped!\n");
    }
}