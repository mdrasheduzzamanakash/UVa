#include <bits/stdc++.h>
using namespace std;
vector<int> g[100],gr[100];
vector<bool> visit;
unordered_map<string , int> no;
unordered_map<int, string> name;
vector<int> component;
stack<int> s;

int n,m;
void dfs(int u){
    visit[u] = true;
    for(int v = 0;v < g[u].size();v++){
        if(visit[g[u][v]] == false){
            dfs(g[u][v]);
        }
    }
    s.push(u);
}

void revDfs(int u){
    visit[u] = true;
    component.push_back(u);
    for(int v = 0;v < gr[u].size();v++){
        if(visit[gr[u][v]] == false){
            revDfs(gr[u][v]);
        }
    }
}

int main() {
    int kse = 1;
    while(cin >> n >> m && (n || m)){
        if(kse != 1) cout << endl;
        for(int i = 0;i < 100;i++) g[i].clear(),gr[i].clear();
        no.clear();
        name.clear();
        string u,v;
        cin >> ws;
        for(int i = 0,idx = 0;i < m;i++){
            cin >> u >> v;
            int a,b;
            if(no.find(u) != no.end())
                a = no[u];
            else {
                name[idx] = u;
                no[u] = idx;
                a = no[u];
                idx++;
            }
            if(no.find(v) != no.end())
                b = no[v];
            else {
                name[idx] = v;
                no[v] = idx;
                b = no[v];
                idx++;
            }
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        visit.assign(30,false);
        for(int i = 0;i < n;i++){
            if(visit[i] == false){
                dfs(i);
            }
        }
        //
        printf("Calling circles for data set %d:\n",kse++);
        visit.assign(30,false);
        while(!s.empty()){
            component.clear();
            int tp = s.top();
            s.pop();
            if(visit[tp] == false){
                revDfs(tp);
                cout << name[component[0]];
                for(int i = 1;i < component.size();i++){
                    cout << ", " << name[component[i]];
                }
                cout << endl;
            }
        }
    }
}