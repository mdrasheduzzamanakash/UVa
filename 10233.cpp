#include <bits/stdc++.h>
using namespace std;

void getXY(int n, int &x,int &y){
    int level=0,sum=1;
    while(sum<=n){
        level++; sum+=level*4;
    }
    sum--;
    x=-level;y=0;
    if(sum-level<=n){
        x+=sum-n;y-=sum-n;return;
    }else x=0,y=-level,sum-=level;

    if(sum-level<=n){
        x+=sum-n,y+=sum-n;return;
    }else x=level,y=0,sum-=level;

    if(sum-level<=n){
        x-=sum-n,y+=sum-n;return;
    }else x=0,y=level,sum-=level;

    x-=sum-n,y-=sum-n;
    return;
}

int main() {
    //         freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int a,b;
    while(cin >> a >> b && (a+b) >= 0){
        int x,y,xx,yy;
        getXY(a,x,y),getXY(b,xx,yy);
        double ans=hypot(x-xx,y-yy);
        printf("%.2lf\n",ans);
    }
}