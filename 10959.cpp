#include <bits/stdc++.h>
using namespace std;
vector<int> g[1010];
bool visit[1010];
int dup[1010][1010];
int no[1010];

void BFS(int s){
    queue<int> q;
    q.push(s);
    visit[s] = true;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int i = 0;i < g[top].size();i++){
            if(visit[g[top][i]] == false){
                visit[g[top][i]] = true;
                no[g[top][i]] = no[top] + 1;
                q.push(g[top][i]);
            }
        }
    }
}




int main() {    
    //     freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        memset(dup,false,sizeof dup);
        memset(no,0,sizeof no);
        memset(visit,false, sizeof visit);
        int p,d;
        cin >> p >> d;
        for(int i = 0;i < p;i++) g[i].clear();
        for(int i = 0;i < d;i++){
            int u,v;
            cin >> u >> v;
            if(dup[u][v] == false){
                g[u].push_back(v);
                g[v].push_back(u);
                dup[u][v] = true;
                dup[v][u] = true;
            }
        }
        BFS(0);
        for(int i = 1;i < p;i++){
            cout << no[i] << endl;
        }
        if(T)cout << endl;
    }

}