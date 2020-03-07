#include <bits/stdc++.h>
using namespace std;
vector<int> graph[250];
int n;
vector<int> tin,low;
vector<bool> visit;
int timer;
int tott[300] = {0};

void dfs(int v, int p = -1){
    visit[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    //
    for(int i : graph[v]){
        if(i == p) continue;
        if(visit[i]){
            low[v] = min(low[v], tin[i]);
        }else{
            dfs(i,v);
            low[v] = min(low[v], low[i]);
            if(low[i] >= tin[v] && p != -1){
                tott[v] = 1;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
        tott[v] = 1;
    }
}


int main() {
    // freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    int n;
    while(cin >> n && n){
        for(int i = 0;i <= n+1;i++) graph[i].clear();
        tin.assign(250,-1);
        low.assign(250,-1);
        visit.assign(250,false);
        memset(tott,0,sizeof tott);
        int u,v;
        timer = 0;


        //
        for(int i = 0;i <= n;i++){
            cin >> u;
            if(u == 0)
                break;
            string s;
            getline(cin, s);
            stringstream ss(s);
            while(ss >> v){
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        //
        
        for(int i = 1;i <= n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }
        cout << count(tott,tott+300,1) << endl;
    }
}