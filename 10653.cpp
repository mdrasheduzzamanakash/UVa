#include <bits/stdc++.h>
using namespace std;
int R,C;
int sx,sy,dx,dy;
int graph[1010][1010];
int dist[1010][1010];
bool visit[1010][1010];

int xx[] = {-1, 1, 0, 0};
int yy[] = {0, 0, 1, -1};

void bfs(){
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    visit[sx][sy] = true;

    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int nx = top.first + xx[i];
            int ny = top.second + yy[i];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if(!visit[nx][ny] && graph[nx][ny] != 1){
                visit[nx][ny] = true;
                dist[nx][ny] = dist[top.first][top.second] + 1;
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    while(cin >> R >> C && (R || C)){
        memset(graph,0,sizeof graph);
        memset(dist,0,sizeof dist);
        memset(visit,false,sizeof visit);
        int pn,r,cnt,cno;
        cin >> pn;
        while(pn--){
            cin >> r >> cnt;
            while(cnt--){
                cin >> cno;
                graph[r][cno] = 1;
            }
        }
        cin >> sx >> sy >> dx >> dy;
        bfs();
        cout << dist[dx][dy] << endl;
    }
}