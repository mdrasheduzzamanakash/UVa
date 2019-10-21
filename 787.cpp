//787
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long x;
    while(cin >> x){
        // int a[110];
        long long max_p,min_p;
        bool flag = true;
        goto level;
        while((scanf("%lld",&x)) && (x != -999999)){
            
            level:
            if(flag){
                max_p = x;
                min_p = x;
                flag = false;
                continue;
            }

            if(x < 0)   swap(max_p,min_p);
            max_p = max(max_p*x , x);
            min_p = min(min_p*x , x);
            
        }
        printf("%lld\n",max_p);
    }
    return 0;
}