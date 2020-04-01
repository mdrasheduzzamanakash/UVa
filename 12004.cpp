#include<bits/stdc++.h>
using namespace std;






int main() {
//         freopen("i.txt","r",stdin);
//    freopen("o.txt","w",stdout);
    int T,n,kse = 1;
    cin >> T;
    while(T--)
    {
        long long int n;
        cin >> n;
        if(n == 1){
            printf("Case %d: 0\n",kse++);
            continue;
        }

        if(n == 2){
            printf("Case %d: 1/2\n",kse++);
            continue;
        }
        n--;
        long long int ans = ((n+1)*n)/2;
        if(ans % 2 == 0){
            printf("Case %d: %lld\n",kse++,ans/2);
        }else{
            printf("Case %d: %lld/2\n",kse++,ans);
        }
    }
}