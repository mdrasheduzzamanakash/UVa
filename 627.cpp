#include <bits/stdc++.h>
using namespace std;
vector<int> g[1000];
int sz;

void bfs(int a, int b,int pst){
    int dis[sz+1] = {10000000};
    int parent[1000] = {0};
    int visit[1000] = {false};
    queue<int> q;

    q.push(a);
    visit[a] = 1;
    dis[a] = 0;
    parent[a] = -1;

    while(!q.empty()){
        int top = q.front(); q.pop();
        for(int i = 0;i < g[top].size();i++){
            if(!visit[g[top][i]]){
                visit[g[top][i]] = 1;
                parent[g[top][i]] = top;
                dis[g[top][i]] = dis[top] + 1;
                q.push(g[top][i]);
            }
        }
    }
    vector<int> path;
    if(!visit[b]) {
        cout << "\nconnection impossible";
        return;
    }
    while(b != -1){
        path.push_back(b);
        b = parent[b];
    }
    reverse(path.begin(),path.end());
    cout << "\n" << path[0];
    for(int i = 1;i < path.size();i++){
        cout << " " << path[i];
    }
}



int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,u,v,kse = 0;
    while(cin >> n){
        for(int i = 1;i <= n;i++){
            g[i].clear();
        }
        sz = n;
        string line;
        for(int i = 0;i  < n;i++){
            cin >> line;
            stringstream ss(line);
            int id,ii; ss >> id; ss.ignore();
            while(ss >> ii){
                g[id].push_back(ii);
                if(ss.peek() == ',') ss.ignore();
            }
        }
        // for(int i = 1;i <= n;i++){
        //     for(int j = 0;j < g[i].size();j++){
        //         cout << g[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cin >> n;
        cin >> ws;
        if(kse == 0)
            cout << "-----";
        else
            cout << "\n-----";
        while(n--){
            getline(cin, line);
            stringstream ss(line);
            ss >> u >> v;
            bfs(u,v,n);
        }
        kse++;
    }
    cout << endl;
}