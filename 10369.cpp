#include <bits/stdc++.h>
using namespace std;
#define mx 505
struct node
{
    int x,y;
    double d;
    bool operator < (node const &o){
        return (this->d < o.d);
    }
    /* data */
};

int parent[mx],Rank[mx];
void Make(int n){
    for(int i = 0;i < n;i++)
        parent[i] = i , Rank[i] = 0;
}
int Find(int n){
    return n == parent[n] ? parent[n] : parent[n] = Find(parent[n]);
}
int Union(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(Rank[a] < Rank[b]) swap(a,b);
        parent[b] = a;
        if(Rank[a] == Rank[b]) Rank[a]++;
        return 1;
    }
    return 0;
}

int main() {
    //             freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T;
    cin >> T;
    while(T--){
        int sat,p;
        cin >> sat >> p;
        node point[p];
        for(int i = 0;i < p;i++){
            cin >> point[i].x >> point[i].y;
        }
        node list[250100];
        int m = 0;
        for(int i = 0;i < p;i++){
            for(int j = i+1;j < p;j++){
                if(i == j)continue;
                int a = point[i].x - point[j].x;
                int b = point[i].y - point[j].y;
                list[m].x = i;
                list[m].y = j;
                list[m].d = sqrt(a*a + b*b);
                m++;
            }
        }
        sort(list,list+m);
        Make(p);
        // for(int i = 0;i < m;i++){
        //     cout << list[i].d << endl;
        // }
        double ans ;
        int cnt = 0;
        for(int i = 0;i < m;i++){
            if(Union(list[i].x , list[i].y)){
                cnt++;
                if(cnt == p-sat){
                    ans = list[i].d;
                    break;
                }
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
}