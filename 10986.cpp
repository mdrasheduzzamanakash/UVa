#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T,kse = 0;
    cin >> T;
    while(T--){
        kse++;
        int n,m,s,d;
        cin >> n >> m >> s >> d;
        vector<pair<int,int>> g[n];
        while(m--){
            int u,v,c;
            cin >> u >> v >> c;
            g[u].push_back(make_pair(v,c));
            g[v].push_back(make_pair(u,c));
        }

        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> q;
        int dist[n];
        memset(dist,0x3f,sizeof dist);
        q.push(make_pair(0,s));
        dist[s] = 0;

        while(!q.empty()){
            pair<int,int> t = q.top();
            int u = t.second;
            q.pop();

            vector<pair<int,int>> :: iterator i;
            for(i = g[u].begin();i != g[u].end();i++){
                int v = i->first;
                int len = i->second;

                if(dist[v] > dist[u] + len){
                    dist[v] = dist[u] + len;
                    q.push(make_pair(dist[v],v));
                }
            }

        }

        if(dist[d] == 0x3f || dist[d] == 1061109567){
            printf("Case #%d: unreachable\n",kse);
        }else {
            printf("Case #%d: %d\n",kse,dist[d]);
        }
    }
}