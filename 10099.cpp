#include <bits/stdc++.h>
using namespace std;
#define mx 1000001

struct node
{
    int x,y,d;
    bool operator < (node const &o){
        return !(this->d < o.d);
    }
    /* data */
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
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int n,m,kse = 0;
    while(cin >> n >> m && (n || m)){
        if(kse)cout << endl;
        node list[m];
        for(int i = 0;i < m;i++){
            cin >> list[i].x >> list[i].y >> list[i].d;
        }
        int s,d,t;
        cin >> s >> d >> t;
        sort(list,list+m);
        Make(n);
        int mn;
        for(int i =0 ;i < m;i++){
            if(Find(s) == Find(d)){
                break;
            }
            if(Union(list[i].x , list[i].y)){
                mn = list[i].d;
            }
        }
        // cout << mn << endl;
        mn--;
        if((t) % mn == 0){
            mn = (t) / mn;
        }else {
            mn = (t) / mn;
            mn++;
        }
        printf("Scenario #%d\nMinimum Number of Trips = %d\n",++kse,mn);
    }
    cout << endl;
}