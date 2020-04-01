#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x,y,d;
    bool operator < (node const &o){
        return this->d < o.d;
    }
};

int parent[10001];
int Rank[10001];
void Make(int n){
    for(int i = 1;i <= n;i++){
        parent[i] = i;
        Rank[i] = 0;
    }
}

int Find(int n){
    return n == parent[n] ? parent[n] : Find(parent[n]);
}

int Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if(x != y){
        if(Rank[x] < Rank[y])
            swap(x,y);
        parent[y] = x;
        if(Rank[x] == Rank[y])
            Rank[x]++;
        return 1;
    }
    return 0;
}
vector<int> g[10001];
bool visit[10001];

void dfs(int v){
    visit[v] = true;
    for(int u = 0;u < g[v].size();u++){
        if(!visit[g[v][u]]){
            dfs(g[v][u]);
        }
    }
}

int main() {
    //     freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T,kse = 0;
    cin >> T;
    while(T--){
        int n,m,a;
        cin >> n >> m >> a;
        node list[m];
        for(int i = 0;i < m;i++){
            cin >> list[i].x >> list[i].y >> list[i].d;
        }
        sort(list,list+m);
        Make(n);
        long long sum = 0;
        for(int i = 0;i < m;i++){
            if(list[i].d >= a) continue;
            if(Union(list[i].x , list[i].y)){
                sum += list[i].d;
                g[list[i].x].push_back(list[i].y);
                g[list[i].y].push_back(list[i].x);
            }
        }
        // dfs
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(!visit[i]){
                cnt++;
                dfs(i);
            }
        }
        // cout << cnt <<endl;
        //op
        long long tot = sum + (cnt*a);
        cout << "Case #" << ++kse << ": " << tot << " " << cnt << endl;
        for(int i = 0;i <= n;i++)
            visit[i] = false,g[i].clear();
    }
    return 0;
}