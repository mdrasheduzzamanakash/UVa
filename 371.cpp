#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    ll a,b,v,mx = -1;
    while(scanf("%lld %lld",&a,&b) == 2){
        if(a > b) swap(a,b);
        if(a == 0 && b == 0) break;
        ll c = a;
        ll d = b;
        if(a > b) swap(a,b);
        mx = -1;
        for(ll i = a;i <= b;i++){
            ll temp = i,cnt = 0;
            while(1){
                cnt++;
                if(temp % 2 == 0) temp /= 2;
                else temp = temp*3 + 1;
                if(temp == 1) break;
            }
            if(cnt > mx){
                mx = cnt; v = i;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",c,d,v,mx);
    }
}