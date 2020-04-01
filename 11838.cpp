#include <bits/stdc++.h>
using namespace std;
int n,m,p,u,v;
vector<int> g[2001],gr[2001];
vector<bool> visit,rvisit;
stack<int> st;
void debug(){cout << "debug" << endl;}
void reset(int n){
    for(int i = 1;i <= n;i++) g[i].clear(), gr[i].clear();
    visit.assign(n+1,false);
    rvisit.assign(n+1,false);
}
void input(int n,int m){
    while(m--){
        cin >> u >> v >> p;
        if(p == 1){
            g[u].push_back(v);
            gr[v].push_back(u);
        }else if(p == 2){
            g[u].push_back(v);
            g[v].push_back(u);
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
    }
}

void dfs(int u){
    visit[u] = true;
    for(int i = 0;i < g[u].size();i++){
        if(!visit[g[u][i]]){
            dfs(g[u][i]);
        }
    }
    st.push(u);
}

void rdfs(int u){
    rvisit[u] = true;
    for(int i = 0;i < gr[u].size();i++){
        if(!rvisit[gr[u][i]]){
            rdfs(gr[u][i]);
        }
    }
}

int main() {
    //       freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);
    while(cin >> n >> m && (n || m)){
        reset(n);
        input(n,m);
        //
        int tot = 0;
        for(int i = 1;i <= n;i++){
            if(!visit[i]){
                dfs(i);
            }
        }
        //
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(!rvisit[u]){
                rdfs(u);
                tot++;
            }
        }

        if(tot > 1){
            cout << 0 << endl;
        }else if(tot == 1){
            cout << 1 << endl;
        }

    }
}