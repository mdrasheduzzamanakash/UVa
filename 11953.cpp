#include <bits/stdc++.h>
using namespace std;
char graph[150][150];
int ans,N,sz;
void dfsHorizontal(int x, int y, int bk){
    if(y < 0 || y >= N || x < 0 || x >= N || graph[x][y] == '.') return;
    graph[x][y] = '.';
    dfsHorizontal(x,y+1,bk);
    dfsHorizontal(x,y-1,bk);
    dfsHorizontal(x+1,y,bk);
    dfsHorizontal(x-1,y,bk);
}

int main(){
    // testing 
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int kase;
    cin >> kase;
    for(int t = 1;t <= kase;t++){
        ans = 0;
        cin >> N;
        sz = ceil(N/2);
        for(int i = 0;i < N;i++) cin >> graph[i];
        // inp fin
        for(int i = 0;i < N;i++)
            for(int j = 0;j < N; j++){
                if(graph[i][j] == 'x'){
                    // .. for horizontal
                    ans++;
                    dfsHorizontal(i,j,0);
                    // .. for vertical
                    // vP = false;
                    // dfsVertical(i+1,j,0);
                    // if(vP) ans++;
                }
            }

        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}