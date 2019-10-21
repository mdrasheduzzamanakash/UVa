#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main(){
    int t,i,c = 1;
    char a[20];
    long long fac[25] = {1,1};
    for(i = 2;i <= 20;i++){
        fac[i] = fac[i-1]*i;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        int di[26] = {0},l = strlen(a);
        for(i = 0;  a[i];i++){
            di[a[i]-'A']++;
        }

        long long finalAns = fac[l];
        for(i = 0;i < 26;i++){
            finalAns /= fac[di[i]];
        }

        printf("Data set %d: %lld\n", c++, finalAns);

    }
    return 0;
}