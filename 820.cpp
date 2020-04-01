#include <bits/stdc++.h>
using namespace std;


#define N 120
int cap[N][N], parent[N], n, s,t,c;

bool bfs() {
    queue<int> q;
    q.push(s);
    memset(parent, -1, sizeof parent);
    parent[s] = s;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (u == t)
            return true;
        for (int v = 0; v < n; ++v)
            if (parent[v] == -1 && cap[u][v])
                parent[v] = u, q.push(v);
    }
    return false;
}
 

int maxFlow(){
    int mf = 0;
    int f;
    while(bfs()){
        int f = 1e8;
        int v = t;
        while(parent[v] != v)
            f = min(f, cap[parent[v]][v]), v = parent[v];
        v = t;
        mf += f;
        while(parent[v] != v)
            cap[parent[v]][v] -= f, cap[v][parent[v]] += f,v = parent[v];
    }
    return mf;
}


int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    for(int kse = 1;;kse++){
        cin >> n; if(n == 0) break;
        memset(cap, 0, sizeof cap);
        cin >> s >> t >> c;
        --s; --t;
        for(int i = 0,x,y,z;i < c;i++){
            cin >> x >> y >> z;
            --x; --y;
            cap[x][y] += z, cap[y][x] += z;
        }
        printf("Network %d\n", kse);
        printf("The bandwidth is %d.\n\n", maxFlow());
    }
}