#include <bits/stdc++.h>
using namespace std;
vector<int> g[110];
bool visit[110];
vector<int> ans;

void dfs(int x){
    if(visit[x] == true) return;
    visit[x] = true;

    for(int i = 0;i < g[x].size();i++){
        dfs(g[x][i]);
    }
    ans.push_back(x);
}

int main(){
    int n,m;
    while(cin >> n >> m , n || m){
        for(int i = 0;i <= n;i++) g[i].clear();
        memset(visit, false, sizeof visit);

        int x,y;
        for(int i = 0;i < m;i++){
            cin >> x >> y;
            g[x].push_back(y);
        }

        for(int i = 1;i <= n;i++){
            dfs(i);
        }

        reverse(ans.begin(),ans.end());
        cout << ans[0];
        for(int i = 1;i < n;i++){
            cout << " " << ans[i];
        }
        cout << endl;
    }
}