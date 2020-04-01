#include <bits/stdc++.h>
using namespace std;


int p[755],r[755];
struct edg
{
    int x,y,d;
    bool operator <(edg const &o){
        return this->d < o.d;
    }
    /* data */
};
void Make(int n){
    for(int i = 0;i <= n;i++){
        p[i] = i;
        r[i] = 1;
    }
}

int findp(int n){
    return n == p[n] ? n : p[n]=findp(p[n]);
}
int Union(int x,int y){
    x = findp(x);
    y = findp(y);
    if(x != y){
        if(r[x] < r[y]) swap(x,y);
        p[y] = x;
        if(r[x] == r[y]) r[x]++;
        return 1;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        edg list[755*755];
        int x[755],y[755];
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> x[i] >> y[i];
        Make(n);
        int m;cin >> m;
        int cnt = 0;
        while(m--){
            int a,b;
            cin >>  a >> b;
            cnt += Union(a,b);
        }
        if(cnt == n-1){
            puts("No new highways need");
        }else {
            m = 0;
            for(int i = 1;i <= n;i++){
                for(int j = i+1; j <= n;j++){
                    list[m].x = i;
                    list[m].y = j;
                    list[m].d = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                    m++;
                }
            }
            sort(list,list+m);
            for(int i = 0;i < m;i++){
                if(Union(list[i].x, list[i].y)){
                    printf("%d %d\n",list[i].x, list[i].y);
                }
            }
        }
        if(t) puts("");
    }
}