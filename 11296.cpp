#include <bits/stdc++.h>
using namespace std;


int main() {
    unsigned long long n;
    while(scanf("%llu",&n)==1){
        n = (n/2);
        printf("%llu\n",(n+2)*(n+1)/2);
    }
    return 0;
}