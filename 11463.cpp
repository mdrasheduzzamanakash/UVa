#include <bits/stdc++.h>
using namespace std;
#define INF 0xfffffff







int main() {
    int T;
    cin >> T;
    for(int kse = 1;kse <= T;kse++){
        int n,m;
        cin >> n >> m;
        int adj[n][n] = {};
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                adj[i][j] = INF;
        for(int i = 0;i < n;i++)
            adj[i][i] = 0;
        
        for(int i = 0;i < m;i++){
            int a,b;
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        for(int k = 0;k < n;k++){
            for(int i = 0;i < n;i++){
                for(int j = 0;j < n;j++){
                    if(adj[i][j] == INF ||
                        adj[i][k]+adj[k][j] < adj[i][j]){
                            if(adj[i][k] && adj[k][j]){
                                adj[i][j] = adj[i][k] + adj[k][j];
                            }
                        }
                }
            }
        }

        int s,e;
        cin >> s >> e;
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans , (adj[s][i] + adj[e][i]));
        }

         printf("Case %d: %d\n", kse, ans);
    }
}