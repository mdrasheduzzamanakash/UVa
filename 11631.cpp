#include <bits/stdc++.h>
using namespace std;
#define mx  200001
int Rank[mx],Parent[mx];

struct edge{
    int x,y,d;
    bool operator < (edge const &o){
        return this->d < o.d;
    }
};
void make_set(int n){
    for(int i = 0;i < n;i++)
        Parent[i] = i,Rank[i] = 0;
}

int Find_set(int v){
    return Parent[v] == v ? Parent[v] : Find_set(Parent[v]);
}


void connect(int x,int y){
    if(Rank[x] < Rank[y])
        swap(x,y);
    Parent[y] = x;
    if(Rank[x] == Rank[y])
        Rank[x]++;
}


int Union(int x,int y){
    x = Find_set(x);
    y = Find_set(y);

    if(x != y){
        connect(x,y);
        return 1;
    }
    return 0;
}




int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,f = true;
    while(cin >> n >> m && (n || m)){
        int tot = 0;
        make_set(n);
        edge edges[m];
        for(int i = 0;i < m;i++){
            cin >> edges[i].x >> edges[i].y >> edges[i].d;
            tot += edges[i].d;
        }

        int cost = 0;
        sort(edges,edges+m);
        for(int i = 0;i < m;i++){
            cost += Union(edges[i].x, edges[i].y) * edges[i].d;
        }
        cout << tot - cost << endl;
    }
}