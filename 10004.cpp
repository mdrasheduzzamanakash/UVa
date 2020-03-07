#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;

int main(){
    int n;
    while(cin >> n && n){
        graph.clear();
        graph.resize(n);
        int l;
        cin >> l;
        for(int i = 0;i < l;i++){
            int a,b;;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        //.............
        vector<int> side(n,-1);
        bool isBipartite = true;
        queue<int>q;
        for(int st = 0;st < n;st++){
            if(side[st] == -1){
                q.push(st);
                side[st] = 0;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(auto u : graph[v]){
                        if(side[u] == -1){
                            side[u] = side[v] ^ 1;
                            q.push(u);
                        }else {
                            isBipartite &= side[u] != side[v];
                        }
                    }
                }
            }
        }

        isBipartite ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }
    return 0;
}