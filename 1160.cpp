#include <bits/stdc++.h>
using namespace std;
#define mx 100100
int parent[mx],Rank[mx];
void Make(){
    for(int i = 0;i < mx;i++)
        parent[i] = i, Rank[i] = 0;
}

int Find(int n){
    return parent[n] == n ? parent[n] : Find(parent[n]);
}

void Union(int u,int v){
    u = Find(u); v = Find(v);
    if(u != v){
        if(Rank[u] < Rank[v])swap(u,v);
        parent[v] = u;
        if(Rank[u] == Rank[v]) Rank[u]++;
    }
}

int main() {
    //         freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
   int x,y;
   while(cin >> x){
       Make();
       int ans = 0;
       while(cin >> y){
           if(Find(x) != Find(y)){
               Union(x,y);
           }else{
               ans++;
           }
           cin >> x;
           if(x == -1) break;
       }
       cout << ans << endl;
   }
}