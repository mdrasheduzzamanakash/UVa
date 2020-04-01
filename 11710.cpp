#include <bits/stdc++.h>
using namespace std;
#define mx 80000
map<string ,int> no;
map<int, string> name;
struct edge{
    int x,y,d;
    bool operator < (edge const &o){
        return this->d < o.d;
    }
};

int Rank[mx],Parent[mx];
void Make_Set(int n){
    for(int i = 0;i < n;i++){
        Rank[i] = 0;
        Parent[i] = i;
    }
}
int Find_Parent(int n){
    return Parent[n] == n ? Parent[n] : Find_Parent(Parent[n]);
}
int Union(int x, int y){
    x = Find_Parent(x);
    y = Find_Parent(y);
    if(x != y){
        if(Rank[x] < Rank[y])
            swap(x,y);
        Parent[y] = x;
        if(Rank[x] == Rank[y])
            Rank[x]++;
        return 1;
    }
    return 0;
}


void clean(){
    no.clear();
    name.clear();
}
int main() {
    //     freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,c;
    while(cin >> n >> m && (n || m)){
        clean();
        string s,ss;
        edge edges[m];
        for(int i = 0;i < n;i++){
            cin >> s;
            no[s] = i;
            name[i] = s;
        }
        for(int i = 0;i < m;i++){
            cin >> s >> ss >> c;
            int u = no[s];
            int v = no[ss];
            edges[i].x = u;
            edges[i].y = v;
            edges[i].d = c;
        }
        cin >> s;

        // for(int i = 0;i < m;i++){
        //     cout << edges[i].x << " " << edges[i].y << " " << edges[i].d << endl;
        // }

        sort(edges,edges + m);
        int ans = 0;
        int mm = 0;
        Make_Set(n);
        for(int i = 0;i < m;i++){
            if(Union(edges[i].x, edges[i].y)){
                ans += edges[i].d;
                mm++;
            }
        }
        // output
        if(mm == n - 1){
            cout << ans << endl;
        }else{
            cout << "Impossible" << endl;
        }
    }
}