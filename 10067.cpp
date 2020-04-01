#include <bits/stdc++.h>
using namespace std;

int g[10][10][10][10];
int dis[10][10][10][10];
bool visit[10][10][10][10];
int si,sj,sk,sl;
int di,dj,dk,dl;

struct node{
    int i,j,k,l;
};

int pi[] = {1,-1,0,0,0,0,0,0};
int pj[] = {0,0,1,-1,0,0,0,0};
int pk[] = {0,0,0,0,1,-1,0,0};
int pl[] = {0,0,0,0,0,0,1,-1};

bool is_valid(int i,int j,int k,int l){
    if( i < 0 || i > 9 ||
        j < 0 || j > 9 ||
        k < 0 || k > 9 ||
        l < 0 || l > 9)     return false;
    if(g[i][j][k][l] == -1) return false;
    return                         true;
}

void bfs(){
    queue<node> q;
    node s;
    s.l = sl;
    s.i = si;
    s.j = sj;
    s.k = sk;
    q.push(s);
    visit[si][sj][sk][sl] = true;
    dis[si][sj][sk][sl] = 0;
    while(!q.empty()){
        node cur,t = q.front();
        q.pop();
        for(int i = 0;i < 8;i++){
            int ni = t.i + pi[i];
            int nj = t.j + pj[i];
            int nk = t.k + pk[i];
            int nl = t.l + pl[i];

            if(ni == -1) ni = 9;
            if(nj == -1) nj = 9;
            if(nk == -1) nk = 9;
            if(nl == -1) nl = 9;

            if(ni == 10) ni = 0;
            if(nj == 10) nj = 0;
            if(nk == 10) nk = 0;
            if(nl == 10) nl = 0;

            if(is_valid(ni,nj,nk,nl) && !visit[ni][nj][nk][nl]){
                visit[ni][nj][nk][nl] = true;
                dis[ni][nj][nk][nl] = dis[t.i][t.j][t.k][t.l] + 1;
                cur.i = ni;
                cur.j = nj;
                cur.k = nk;
                cur.l = nl;
                q.push(cur);
            }
        }
    }
}

int main() {
    //     freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        for(int i = 0; i < 10;i++)
            for(int j = 0;j < 10;j++)
                for(int k = 0;k < 10;k++)
                    for(int l = 0;l < 10;l++)
                        visit[i][j][k][l] = false,g[i][j][k][l] = 0,dis[i][j][k][l] = 0;

        cin >> si >> sj >> sk >> sl;
        cin >> di >> dj >> dk >> dl;
        int n,fi,fj,fk,fl;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> fi >> fj >> fk >> fl;
            g[fi][fj][fk][fl] = -1;
        }
        bfs();
        if(visit[di][dj][dk][dl])
            cout << dis[di][dj][dk][dl] << endl;
        else
            cout << -1 << endl;
    }
}