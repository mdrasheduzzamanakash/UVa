#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    while(scanf("%d",&n)==1){
        if(n==1){
            printf("TERM %d IS %d/%d\n",n,1,1); continue;
        }
        int line=ceil((-1+sqrt(1+4*2*n))/2);
        if(line%2==0){
            int t=n-((line-1)*line)/2;
            printf("TERM %d IS %d/%d\n",n,t,line-t+1);
        }else{
            int t=n-((line-1)*line)/2;
            printf("TERM %d IS %d/%d\n",n,line-t+1,t);
        }
    }
    return 0;
}