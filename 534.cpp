#include <bits/stdc++.h>
using namespace std;
#define mx 200001
int nodes;
struct node
{
    int x,y;
    double d;
    bool operator < (node const &o){
        return this->d < o.d;
    }
};
node point[mx],edges[mx];
int Parent[mx],Rank[mx];
void Make(int n){
    for(int i = 0;i < n;i++){
        Parent[i] = i;
        Rank[i] = 0;
    }
}
int FindParent(int v){
    return v == Parent[v] ? Parent[v] : FindParent(Parent[v]);
}
int Union(int x, int y){
    x = FindParent(x);
    y = FindParent(y);
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
int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int kse = 0;
    while(cin >> nodes && nodes){
        for(int i = 0;i < nodes;i++){
            cin >> point[i].x >> point[i].y;
        }
        int id = 0;
        for(int i = 0;i < nodes ;i++){
            for(int j = 0;j < nodes;j++){
                int a = point[i].x - point[j].x;
                int b = point[i].y - point[j].y;
                double c = sqrt(a*a + b*b);
                edges[id].x = i;
                edges[id].y = j;
                edges[id].d = c;
                id++;
            }
        }
        Make(nodes);
        sort(edges,edges+id);
        double mn;
        for(int i = 0;i < id;i++){
            if(FindParent(0) == FindParent(1)) break;
            if(Union(edges[i].x,edges[i].y)){
                mn = edges[i].d;
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++kse,mn);
    }
}
