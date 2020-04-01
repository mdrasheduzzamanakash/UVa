#include <bits/stdc++.h>
using namespace std;
#define INF 0xfffffff







int main() {
    //  freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,kse = 1;
    while(cin >> n >> m && (n || m)){
        map<int,string> name;
        map<string,int> no;
        int adj[n+1][n+1] = {0};
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                if(i == j) adj[i][j] = 0;
                else       adj[i][j] = INF;
            }
        }
        for(int i = 1;i <= n;i++){
            string s; cin >> s;
            no[s] = i, name[i] = s;
        }
        for(int i = 0;i < m;i++){
            int a,b,w;
            cin >> a >> b >> w;
            adj[a][b] = w;
            adj[b][a] = w;
        }
        for(int k = 1;k <= n;k++){
            for(int i = 1;i <= n;i++){
                for(int j = 1;j <= n;j++){
                    if(adj[i][j] == INF || 
                        adj[i][k]+adj[k][j] < adj[i][j]){
                            if(adj[i][k] != INF && adj[k][j] != INF){
                                adj[i][j] = adj[i][k] + adj[k][j];
                            }
                        }
                }
            }
        }
        int idx,mn = INF,sum;
        for(int i = 1;i <= n;i++){
            sum = 0;
            for(int j = 1;j <= n;j++){
                sum = sum + adj[i][j];
            }
            if(mn > sum)
                mn = sum , idx = i;
        }
        cout << "Case #" << kse++ << " : " << name[idx] << endl;
    }
    return 0;
}