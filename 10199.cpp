#include <bits/stdc++.h>
using namespace std;
int n,m,timer;
vector<int> graph[150];
vector<bool> visit;
vector<int> tin, low;
map<string , int> no;
map<int, string> name;
set<string> ans;

void dfs(int node, int parent = -1){
    visit[node] = true;
    tin[node] = low[node] = timer++;
    int child = 0;
    for(int i : graph[node]){
        if(i == parent) continue;
        if(visit[i] == true){
            low[node] = min(low[node], tin[i]);
        }else {
            dfs(i, node);
            low[node] = min(low[node], low[i]);
            if(low[i] >= tin[node] && parent != -1){
                ans.insert(name[node]);
            }
            child++;
        }
    }
    if(parent == -1 && child > 1){
        ans.insert(name[node]);
    }
}


int main() {
    //      freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    int n,kse = 0;
    while(cin >> n && n){
        if(kse != 0)cout << endl;
        for(int i = 0;i < 150;i++) graph[i].clear();
        visit.assign(n+1, false);
        tin.assign(n+1, -1);
        low.assign(n+1, -1);
        no.clear();
        name.clear();
        ans.clear();
        timer = 0;
        string s;
        cin >> ws;
        for(int i = 0;i < n;i++){
            cin >> s;
            no[s] = i;
            name[i] = s;
        }
        cin >> m;
        while(m--){
            string u,v;
            cin >> u >> v;
            int a = no[u];
            int b = no[v];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        //
        for(int i = 0;i < n;i++){
            if(visit[i] == false){
                dfs(i);
            }
        }
        kse++;
        int sz = ans.size();
        printf("City map #%d: %d camera(s) found\n",kse,sz);
        for(string i : ans){
            cout << i << endl;
        }
    } 
}