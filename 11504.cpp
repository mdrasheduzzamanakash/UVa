#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000010],gr[1000010];
bool visit[1000010] = {false},visit1[1000010] = {false};
stack<int> s;
int n,m,tot;

void dfs(int u){
    visit[u] = true;
    for(int i=0;i<g[u].size();i++){
        int x=g[u][i];
        if(!visit[x]){
            visit[x];
            dfs(x);
        }
    }
    s.push(u);
}

void dfs1(int u){
    visit1[u]=true;
    for(int i=0;i<g[u].size();i++){
        int x=g[u][i];
        if(!visit1[x]){
            visit1[x]=true;
            dfs1(x);
        }
    }
}

int main(){
    int T,a,b;
    cin >> T;
    while(T--){
        cin >> n >> m;
        memset(visit,false,sizeof visit);
        memset(visit1,false,sizeof visit1);
        for(int i = 0;i <= n;i++)
            g[i].clear();
        tot = 0;
        //
        for(int i = 0;i < m;i++){
            cin >> a >> b;
            g[a].push_back(b);
            // gr[b].push_back(a);
        }
        for(int i = 1;i <= n;i++){
            if(visit[i] == false){
                dfs(i);
            }
        }
        
        
        while(!s.empty()){
            int t = s.top();
            if(visit1[t] == false){
                tot++;
                dfs1(t);
            }
            s.pop();
        }

        cout << tot << endl;
    }
}
