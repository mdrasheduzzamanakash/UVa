#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    while(cin >> n && n){
        if(n <= 100){
            printf("f91(%lld) = 91\n",n);
        }else{
            printf("f91(%lld) = %lld\n",n,n-10);
        }
    }
}