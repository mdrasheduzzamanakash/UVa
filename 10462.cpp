#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
vector<int> second;
struct node
{
    bool taken = false;
    int x,y,d;
    bool operator < (node const &o){
        return (this->d < o.d);
    }
    /* data */
};


int parent[105];
int Rank[105];
void Make(int n){
    for(int i = 1;i <= n;i++){
        parent[i] = i;
        Rank[i] = 0;
    }
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
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int T,kse = 0;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int inmst[m];
        node list[m];
        for(int i = 0;i < m;i++){
            cin >> list[i].x >> list[i].y >> list[i].d;
        }
        sort(list,list+m);
        Make(n);
        for(int i = 0;i < m;i++)
        inmst[i] = 0;
        int takenEdges=0;
        for(int i = 0;i < m;i++){
            if(Union(list[i].x,list[i].y)){
                takenEdges++;
                inmst[i] = 1;
            }
        }
        if(takenEdges != n-1){
             printf("Case #%d : No way\n",++kse);
             continue;
        }
        
        second.clear();
        for(int ii = 0;ii < m;ii++){
            if(inmst[ii] == true){
                int tkn = 0,w = 0;
                Make(n);
                for(int i = 0;i < m;i++){
                    if(i == ii)continue;
                    if(Union(list[i].x,list[i].y)){
                        w += list[i].d;
                        tkn++;
                    }
                }
                if(tkn == n-1)second.push_back(w);
            }
        }
        sort(second.begin(),second.end());
        if(second.size() == 0){
            printf("Case #%d : No second way\n",++kse);
        }
        else {
            printf("Case #%d : %d\n",++kse,second[0]);
        }
    }
}