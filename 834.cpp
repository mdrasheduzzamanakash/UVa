#include <bits/stdc++.h>
using namespace std;

void rec(int a, int b,int i){
    if(b == 0)return;
    int d = a / b;
    printf("%d",d);
    if(i == 0 && a%b != 0)printf(";");
    else if(a%b != 0)     printf(",");

    rec(b,a%b,1);
}


int main() {

    //  freopen("i.txt","r",stdin);
    // freopen("o.txt","w",stdout);
    int a,b;
    while(scanf("%d%d",&a,&b) == 2){
        printf("[");
        rec(a,b,0);
        printf("]\n");
    }
}