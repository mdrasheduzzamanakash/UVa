#include <bits/stdc++.h>
using namespace std;






int main() {
    unsigned long long n=7,k,temp;
    for(int c=1;c<=10;c++){
        while (1){
            n++;
            temp=(n*n+n)/2;
            k=sqrt(temp);
            if(k*k==temp){
                printf("%10llu%10llu\n",k,n);break;
            }
        }
    }
}