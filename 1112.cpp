#include <bits/stdc++.h>
#define inf 10000000
using namespace std;
typedef pair<int,int> ii;
int N,E,Time,M;
vector<ii> g[101];
int dis[101];
int dij(int s){
    priority_queue<ii> pq;
    for(int i = 0;i <= N;i++) dis[i] = inf;
    pq.push(make_pair(s,0));
    dis[s] = 0;

    while(!pq.empty()){
        int from = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(dis[from] == cost && dis[from] <= Time){
            for(int i = 0;i < (int)g[from].size();i++){
                int to = g[from][i].first;
                int len = g[from][i].second;

                if(dis[to] > dis[from] + len){
                    dis[to] = dis[from] + len;
                    pq.push(ii(to,dis[to]));
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1;i <= N;i++){
        if(dis[i] <= Time)
            ans++;
    }
    return ans;
}



int main() {
    //         freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> E >> Time;
        cin >> M;
        while(M--){
            int from,to,t;
            cin >> from >> to >> t;
            g[to].push_back(ii(from,t));
        }
        printf("%d\n",dij(E));
        if(T)cout << endl;
        for(int i = 0;i <= N;i++)g[i].clear();
    }
    return 0;
}