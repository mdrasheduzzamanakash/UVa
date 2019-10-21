#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[3000];
    int n,size,i,j,temp,d;
    while(scanf("%d",&n) == 1){
        a[0] = 1; size = 1; temp = 0;
        for(i = 1;i <= n;i++){
            for(j = 0;j < size;j++){
                d = a[j]*i + temp;
                a[j] = d%10;
                temp =d / 10;
            }
            while(temp > 0){
                a[size] = temp % 10;
                temp /= 10;
                size++;
            }
        }

        printf("%d!\n",n);
        for(i = size-1;i >= 0;--i)
            printf("%d",a[i]);
                printf("\n");
    }
    return 0;
}