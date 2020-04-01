#include <bits/stdc++.h>
using namespace std;
#define inf 2147483646
typedef pair<int, pair<int,int>> iii;

bool is_valid(int n,int m,int x,int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}



int main() {
    //     freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    int n,m;
    while(T--){
        cin >> n >> m;
        int g[n][m];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin >> g[i][j];
       
       int dis[n][m];
       for(int i = 0;i < n;i++){
           for(int j = 0;j < m;j++){
               dis[i][j] = inf;
           }
       }
       priority_queue<iii, vector<iii> , greater<iii>> q;
       q.push(iii(0,make_pair(0,0)));
       dis[0][0] = g[0][0];

       
       int dx[] = {0,0,1,-1};
       int dy[] = {1,-1,0,0};
       while(!q.empty()){
           iii t = q.top();
           q.pop();
           int ux = t.second.first;
           int uy = t.second.second;
           
           for(int i = 0;i < 4;i++){
               int vx = ux + dx[i];
               int vy = uy + dy[i];
               int len = g[vx][vy];

               if(is_valid(n,m,vx,vy) && dis[vx][vy] > dis[ux][uy] + len ){
                   dis[vx][vy] = dis[ux][uy] + len;
                   q.push(iii(dis[vx][vy],make_pair(vx,vy)));
               }
           }
       }
       cout << dis[n-1][m-1] << endl;
    }
}