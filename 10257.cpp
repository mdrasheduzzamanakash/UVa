#include <bits/stdc++.h>
using namespace std;
int main() {
    int s,p,y,j;
    while(scanf("%d%d%d%d",&s,&p,&y,&j) != EOF){
        int x = ((12+j)-(p+y))/3;
        int r = ((12+j)-(p+y)) - 3*x;
        if(r==0){
            printf("%d %d %d\n",x+y,x+p,x);
        }else if(r == 2){
            printf("%d %d %d\n",x+y+1,x+p+1,x);
        }else{
            if(p+s!=y){
                printf("%d %d %d\n",x+y,x+p+1,x);
            }else {
                printf("%d %d %d\n",x+y+1,x+p,x);
            }
        }
    }
}