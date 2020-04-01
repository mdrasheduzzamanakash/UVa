#include <bits/stdc++.h>
using namespace std;


int main() {
    // freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    long long int n;
    while(scanf("%lld",&n)==1){
        if(n==1){
            printf("1/1\n"); continue;
        }
        long long int line=ceil((-1+sqrt(1+4*2*n))/2);
        long long int t=n-((line-1)*line)/2;
        printf("%lld/%lld\n",line-t+1,t);
    }
    return 0;
}