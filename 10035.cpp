#include <bits/stdc++.h>
using namespace std;




int main() {
    //      freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int a,b,c;
    while(scanf("%lld%lld",&a,&b) == 2){
        if(a == 0 && b == 0)break;
        if(a < b)swap(a,b);
        long long int cnt = 0;
        c = 0;
        while(1){
            long long int aa = a%10;
            long long int bb = b%10;
            if(aa+bb+c > 9){
                // cout << aa << bb << endl;
                 c = (aa+bb+c)/10;
                 cnt++;
            }else{
                c = 0;
            }
            a /= 10;
            b /= 10;
            if(a == 0 && b == 0) break;
        }
        if(cnt == 0)printf("No carry operation.\n");
        else if(cnt == 1) printf("%lld carry operation.\n",cnt);
        else printf("%lld carry operations.\n",cnt);
    }
    return 0;
}