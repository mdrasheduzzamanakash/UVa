#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[3000];
    int n,size,i,j,temp,d;
    while(scanf("%d",&n) == 1){
        int c[15] = {0};
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

        for(int i = 0;i < size;i++)c[a[i]]++;
        printf("%d! --\n",n);
        printf("(0) %d (1) %d (2) %d (3) %d (4) %d\n",c[0],c[1],c[2],c[3],c[4]);
        printf("(5) %d (6) %d (7) %d (8) %d (9) %d\n",c[5],c[6],c[7],c[8],c[9]);
    }
    return 0;
}