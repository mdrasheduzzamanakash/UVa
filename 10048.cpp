#include <bits/stdc++.h>
using namespace std;
#define mx 100000
struct node
{
    int x,y,d;
    bool operator < (node const &o){
        return this->d < o.d;
    }
};

int p[mx],r[mx];
void Make(int n){
    for(int i = 1;i <= n;i++)
        p[i] = i, r[i] = 0;
}
int Find(int n){
    return n == p[n] ? p[n] : Find(p[n]);
}
int Union(int a,int b){
    a = Find(a);
    b = Find(b);
    if(a != b){
        if(r[a] < r[b]) swap(a,b);
        p[b] = a;
        if(r[a] == r[b]) r[a]++;
        return 1;
    }
    return 0;
}

int main() {
    //             freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,q,kse = 0;
    while(cin >> n >> m >> q && (n || m || q)){
        if(kse) cout << endl;
        node list[m];
        for(int i = 0;i < m;i++){
            cin >> list[i].x >> list[i].y >> list[i].d;
        }
        sort(list,list+m);
        printf("Case #%d\n",++kse);
        for(int i = 0;i < q;i++){
            Make(n);
            int a,b,mn = mx;
            cin >> a >> b;
            //
            for(int ii = 0;ii < m;ii++){
                if(Find(a) == Find(b)){
                    cout << mn << endl;
                    break;
                }
                if(Union(list[ii].x,list[ii].y)){
                    mn = list[ii].d;
                }
                if(ii == m-1){
                    if(Find(a) == Find(b)){
                        cout << mn << endl;
                    }else {
                        cout << "no path" << endl;
                    }
                }
            }
        }
    }
}