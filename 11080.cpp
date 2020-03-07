#include <bits/stdc++.h>
using namespace std;
int n,e;
int main(){
        //     freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        vector<int> graph[250];
        vector<int> sides(250,-1);
        bool isBip = true;
        cin >> n >> e;
        for(int i = 0;i < e;i++){
            int u,v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //..
        int tot = 0;
        queue<int> q;
        for(int i = 0;i < n;i++){
            if(sides[i] == -1){
                int cnt[2] = {0};
                q.push(i);
                sides[i] = 0;
                cnt[sides[i]]++;
                while(!q.empty()){
                    int v = q.front();
                    q.pop();
                    for(int u : graph[v]){
                        if(sides[u] == -1){
                            sides[u] = sides[v] ^ 1;
                            cnt[sides[u]]++;
                            q.push(u);
                        }else {
                            isBip &= sides[u] != sides[v];
                        }
                    }
                }
                // each cc's
                tot += max(1,min(cnt[0],cnt[1]));
            }
        }

        if(isBip){
            cout << tot << endl;
        }else {
            cout << -1 << endl;
        }
    }
}