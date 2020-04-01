#include <bits/stdc++.h>
using namespace std;



long long int f(long long int x,long long int y){
    if(x==0 || y==0){
        if(x==0&&y==0)return 0;
        else if(x==0){
            return (y*(y+1))/2;
        }else{
            return ((x*(x+1)/2)+x);
        }
    }else{
        long long int l;
        l=x+y;
        return f(0,l)+x;
    }
}


int main() {
    //     freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int T,kse=0;
    cin >> T;
    while(T--){
        long long int a,b,c,d;
        cin >> a >> b >> c >> d;
        printf("Case %lld: %lld\n",++kse,abs(f(a,b)-f(c,d)));
    }
}